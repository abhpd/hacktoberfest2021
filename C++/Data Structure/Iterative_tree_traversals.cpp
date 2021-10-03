void IterativePreInPost(Node* root){
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    
    stack< pair<Node*,int> >s;
    s.push({root,1});
    
    while(!s.empty()){
        Node* temp=s.top().first;
        int state = s.top().second;
        if(state==1){   //pre,state++,left
            pre.push_back(temp->data);
            s.top().second++;
            if(temp->left)
            s.push({temp->left,1});
            
        }else if(state==2){ //in,state++,right
            in.push_back(temp->data);;
            s.top().second++;
            if(temp->right)
            s.push({temp->right,1});
        }else{//post,pop
            post.push_back(temp->data);;
            s.pop();
        }
    }
    int n=pre.size();
    cout<<endl<<"PreOrder : ";
    for(int i=0;i<n;i++)
        cout<<pre[i]<<" ";
    cout<<endl<<"InOrder : ";
    for(int i=0;i<n;i++)
        cout<<in[i]<<" ";
    cout<<endl<<"PostOrder : ";
    for(int i=0;i<n;i++)
        cout<<post[i]<<" ";
    cout<<endl;
}
