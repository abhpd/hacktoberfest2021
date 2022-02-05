void display(){
    if(isEmpty()){
        cout<<"DE Queue Underflow"<<endl;
        return;
    } 
    cout<<"<--Elements of DE Queue are-->"<<endl;
    if(f<=r){
        while(f<=r){
            cout<<deQueue[f]<<endl;
            f++;
        }
    } else {
        while(f<=MAXSIZE-1){
            cout<<deQueue[f]<<endl;
            f++;
        }
        f=0;
        while(f<=r){
            cout<<deQueue[f]<<endl;
            f++;
        }
    }
}