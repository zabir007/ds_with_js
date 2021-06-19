class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

let display = function(head)
{
    if(head===null)
        console.log('list is empty');
    
    let ptr = head;

    while(ptr!=null)
    {
        console.log(ptr.data);
        ptr=ptr.next;
    }
}

let addEnd = function(head, data) {
    let ptr, new_node;
    ptr = head;
    new_node = new Node(data);

    while(ptr.next!==null) {
        ptr = ptr.next;
    }
    ptr.next = new_node;
}

let addBegin = function(head, data) {

	let ptr, new_node;
    ptr = head;
    new_node = new Node(data);

    new_node.next = ptr;
    ptr = new_node;
    return ptr;
}

let addAnyPos = function(head, data, pos) {
    let ptr, new_node;
    ptr = head;
    new_node = new Node(data);

    pos--;
    while(pos!==1)
    {
        ptr = ptr.next;
        pos--;
    }
    new_node.next = ptr.next;
    ptr.next = new_node;
}

let delFirst = function(head)
{
    if(head===null)
        console.log('list is empty');
    let ptr = head;
    ptr = ptr.next;
    return ptr;
}

let delLast = function(head)
{
    if(head===null)
        return null;
    else if (head.next == null) {
        return null;
    } else {
    let ptr = head;
        while (ptr.next.next !== null)
            ptr = ptr.next;
 
        ptr.next = null;
        return head;
    }
}

let delAnyPos = function(head, pos) 
{
    let curr, prev;
    curr = prev = head;
    if(head===null)
        return null;
    else if(pos===1)
    {
        head = curr.next;
    } else {
        while(pos!==1)
        {
            prev = curr;
            curr = curr.next
            pos--;
        }
        prev.next = curr.next
    }
    return head;
}

let delFullList = function(head)
{
    let ptr = head;
    while(ptr!==null)
    {
        ptr = ptr.next;
        head = ptr;
    }
    return head;
}

let reverseList = function(head)
{
    let prev, curr;
    prev = curr = null;
    while(head!==null)
    {
        curr = head.next
        head.next = prev
        prev = head
        head = curr
    }
    head = prev
    return head
}


let head = new Node(10);
addEnd(head,7);
addEnd(head,17);
head = addBegin(head,8);
addAnyPos(head, 77, 3);
head = reverseList(head)

display(head);