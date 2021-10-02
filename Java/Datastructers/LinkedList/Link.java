class Link {
    public int iData;
    public Link next;

    public Link(int id){
        iData=id;
        next=null;

    }

    public void displayLink(){
        System.out.println(iData);
    }
}