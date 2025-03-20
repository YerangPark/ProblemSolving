function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    const onBridgeQ = []; // [탑승 시각, weight]
    let time = 1;
    let leftWeight = weight;
    
    while(truck_weights.length > 0 || onBridgeQ.length > 0) {
        if (onBridgeQ.length > 0) {
            const frontTruck = onBridgeQ[0];

            if (frontTruck.time + bridge_length <= time) {
                leftWeight += frontTruck.weight;
                onBridgeQ.shift();
            }
        }
        
        if (truck_weights[0] <= leftWeight) {
            const truckWeight = truck_weights.shift();
            leftWeight -= truckWeight;
            onBridgeQ.push({time: time, weight: truckWeight});
        }
        time++;
    }
    
    return time - 1;
}