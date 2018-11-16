public class GenericBox <T> {

    private T t;

    public void set(T t) {
        this.t = t;
    }

    public T get() {
        return t;
    }

    public static void main(String[] args) {

        GenericBox<Integer> b = new GenericBox<>();

        b.set(5);

        System.out.println(b.get());


//        BankAccount ba = (BankAccount) b.get();

        System.out.println(b.get());

    }
}