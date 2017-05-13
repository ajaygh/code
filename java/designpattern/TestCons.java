public class Person {
    private String name;
    public Person(){
        name = "Tom";
    }
    public void getName(){
        return name;
    }
}

public class TestCons{
    public static void main(String[] args) {
        Person person = new Person();
        System.out.println("Person name is ", person.getName());
    }
}