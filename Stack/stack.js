const MAX = 4;
let stack_arr = [MAX]
let top = -1;

let  isEmpty = function() {
    if(top=== -1)
        return 1;
    else
        return 0;
}

let isFull = function() {
    if(top===MAX-1)
        return 1;
    else
        return 0;
}

let peek = function() {
    return stack_arr[top]
}

let stack_push = function(data) {
    if(isFull())
        console.log("stack overflow");
    top = top +1;
    stack_arr[top] = data;
}

let stack_pop = function() {
    if(isEmpty()) {
        console.log("stack is empty");
    } else {
    
    stack_arr[top];
    top = top-1;
    }
}

let print = function() {
    for(let i=top; i>=0; i--) {
        console.log(stack_arr[i]);
    }
}

stack_push(1)
stack_push(2)
stack_push(3)



print()
