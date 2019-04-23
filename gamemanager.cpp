function counter {
    count ++;
    if (count == 4) {
        get resource();
        count = 0
    } 
    
}

get resource() {
    count = 0
    give player resource
}
