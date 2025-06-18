question - we have 2 linked list, output should be a single linked list where elements will e uniion of input 2 linked list and it should be in soreted order.


solution - 
    create a map where key = element and value will be the node for that element.
    store the node of first linked list in map
    store the node of second linked list in map
    since map is ordered, so it will keep keys in sorted order and only store the union of both the linked list as it doesn't allow duplicates
    iterate oon map and create linked list