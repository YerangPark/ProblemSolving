#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct Axis {
    int x;
    int y;
};

struct Block {
    vector<Axis> points;
    int width;
    int height;
    int cnt;
};

// 상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
#define MAX_DIR 4

int SIZE;
vector<vector<bool>> visited;
vector<bool> visited1D;
vector<Block> tableBlocks;
vector<Block> blankBlocks;

bool sortAxises(const Axis& a, const Axis& b) {
    return a.x == b.x ? (a.y < b.y) : (a.x < b.x);
}
vector<Axis> bfs(vector<vector<int>>& board, int x, int y, int validValue) {
    vector<Axis> axises;
    queue<Axis> q;
    
    q.push({x, y});
    axises.push_back({x, y});
    
    while (!q.empty()) {
        Axis now = q.front();
        q.pop();
        for (int i=0; i<MAX_DIR; i++) {
            Axis next = {now.x + dx[i], now.y + dy[i]};
            
            // 유효성 체크
            if (next.x < 0 || next.x >= SIZE || next.y < 0 || next.y >= SIZE ||
                visited[next.x][next.y] || board[next.x][next.y] != validValue)
                continue;
            
            visited[next.x][next.y] = true;
            q.push(next);
            axises.push_back(next);
        }
    }

    return axises;
}

Block convertAxisToBlock(vector<Axis> axises) {
    Block block;
    block.cnt = axises.size();
    Axis min = {51, 51};
    Axis max = {-1, -1};
    
    // 0-base 블록 리스트 만들기 위해 min-max 체크
    for (const Axis& axis : axises) {
        if (min.x > axis.x) min.x = axis.x;
        if (min.y > axis.y) min.y = axis.y;
        if (max.x < axis.x) max.x = axis.x;
        if (max.y < axis.y) max.y = axis.y;
    }
    
    // 0-base 블록 넣기
    for (const Axis& axis : axises) {
        block.points.push_back({axis.x - min.x, axis.y - min.y});
    }
    
    // width, height 계산
    block.width = max.y - min.y + 1;
    block.height = max.x - min.x + 1;
    
    
    return block;
}

bool checkValidSize(Block& A, Block& B) {
    // 3-1. 칸 수 동일해야됨
    if (A.cnt != B.cnt) return false;
    // 3-2. 가로:세로 비율이 동일해야됨
    if (!(A.width == B.width && A.height == B.height) &&
        !(A.width == B.height && A.height == B.width)) return false;
    return true;
}

bool checkSameAxises(vector<Axis> A, vector<Axis> B) {
    for (int i=0; i<A.size(); i++) {
        if (A[i].x != B[i].x || A[i].y != B[i].y) return false;
    }
    return true;
}

void rotateAxisesClockWise(Block& block) {
    for (int i=0; i<block.points.size(); i++) {
        int tmpX = block.points[i].x;
        block.points[i].x = block.points[i].y;
        block.points[i].y = block.height - 1 - tmpX;
    }
    int tmpW = block.width;
    block.width = block.height;
    block.height = tmpW;
    return;
}

bool checkSameShapeBlock(Block A, Block B) {
    // 회전 공식 1. x'축은 y축 인덱스가 그대로 오고
    // y'축은 거꾸로 x축이 되네!!!!!!!!!!! 유레카다
    // ✅ x' = y, y' = (size - 1) - x;
    // 🚨 단, 이 방법은 width, height가 동일해야 함. 정사각형 안에 있어야 함.

    // 회전 공식 2. 만약 width, height가 다르더라도 size대신
    // 각 축에 width, height를 사용하면 괜찮지 않을까?
    // ✅ x' = y, y' = (기존 height(바뀐 width) - 1) - x;
    sort(A.points.begin(), A.points.end(), sortAxises);
    for (int i=0; i<MAX_DIR; i++) {
        // 같은 좌표 체크
        sort(B.points.begin(), B.points.end(), sortAxises);
        if (checkSameAxises(A.points, B.points)) {
            return true;
        }
        // B 블록 회전
        rotateAxisesClockWise(B);
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    SIZE = table.size();
    
    // 1. 테이블 위에 있는 블록을 다음과 같이 저장
        // 좌표 리스트 (정렬된 상태, 0-베이스)
        // width, height, 칸 수
    visited = vector<vector<bool>>(SIZE + 1, vector<bool>(SIZE + 1, false));
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (!visited[i][j] && table[i][j] == 1) {
                visited[i][j] = true;
                vector<Axis> axises = bfs(table, i, j, 1);
                // 리턴받은 블록 리스트를 Block으로 형변환 후 푸시
                tableBlocks.push_back(convertAxisToBlock(axises));
            }
        }
    }
    
    // 2. 게임 보드의 빈 칸을 bfs로 찾기
        // 얘도 테이블 블록과 같이 0-base로 (x, y) 저장
            // 제로베이스는 minX, minY를 각각 빼서.
        // width, height, 칸 수
    visited = vector<vector<bool>>(SIZE + 1, vector<bool>(SIZE + 1, false));
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (!visited[i][j] && game_board[i][j] == 0) {
                visited[i][j] = true;
                vector<Axis> axises = bfs(game_board, i, j, 0);
                // 리턴받은 블록 리스트를 Block으로 형변환 후 푸시
                blankBlocks.push_back(convertAxisToBlock(axises));
            }
        }
    }
    
    visited1D = vector<bool>(tableBlocks.size() + 1, false);
    // 3. 게임 보드의 빈 칸에 넣을 수 있는 테이블 블록 찾기
    for (int i=0; i<blankBlocks.size(); i++) {
        for (int j=0; j<tableBlocks.size(); j++) {
            // 같은 사이즈면서 사용한 블록 아니고
            if (!checkValidSize(blankBlocks[i], tableBlocks[j]) || visited1D[j]) continue;
            // 회전시켜서 같은 모양이 나오는지
            if (!checkSameShapeBlock(blankBlocks[i], tableBlocks[j])) continue;
            // 해당 블록 사용 완료
            visited1D[j] = true;
            // 블록 사이즈만큼 answer에 추가
            answer += tableBlocks[j].cnt;
            break;
    }
            
        }
    
    // 와... 찾았는디....... 57분 걸렸다... 이렇게.. 어렵게 푸는 문제겠지?
    
    
    return answer;
}