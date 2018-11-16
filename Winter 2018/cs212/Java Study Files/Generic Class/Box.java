public class Box {

    private Object obj;

    public void set(Object o) {
        this.obj = o;
    }

    public Object get() {
        return obj;
    }

    public static void main(String[] args) {

        Box b = new Box();

        b.set(5);

        System.out.println(b.get());

//        BankAccount i = (BankAccount) b.get();

    //    System.out.println(i);

    }}
