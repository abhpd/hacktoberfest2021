            push(infix[i]);
        }
    }
    while(top!=-1){
        temp = pop();
        postfix+=temp;
    }
    cout<<"Postfix expression: "<<postfix<<endl;
    return 0;
}

bool isOperator(char ch){
    if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='$'){
        return true;
    } else {
        return false;
    }
}

bool isOperand(char ch){
    if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return true;
    } else {
        return false;