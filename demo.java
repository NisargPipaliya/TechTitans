class demo{
    private static demo d = new demo();
    demo(){
        
    }
    public void print(){
        System.out.println("Hello");
    }
    public static void main(String[] args) {
        demo.d.print();
        
    }
}