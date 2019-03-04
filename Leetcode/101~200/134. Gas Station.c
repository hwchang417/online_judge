int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    
    int index, left, right, fuel, target;
    
    //try to walk through each node with left and right directions
    for(index = 0;index < gasSize;index++){
        //right direction
        fuel = 0;
        right = index;
        do{
            fuel += gas[right];
            fuel -= cost[right];
            right = (right == gasSize - 1 ? 0 : right + 1);
        }while(right != index && fuel >= 0);
        
        if(fuel >= 0)
            return index;
    }
    
    return -1;
}