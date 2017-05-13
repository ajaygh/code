//Updates dependent variables. Used in the context EJB(graph of objects)

//Create dependent classes
class DependentObject1 {
    private String data;
    public void setData(String data){
        this.data = data;
    }
    public String getData(){
        return this.data;
    }
}

class DependentObject2 {
    private String data;
    public void setData(String data){
        this.data = data;
    }
    public String getData(){
        return this.data;
    }
}

class CourseGrainedObject {
    private DependentObject1 do1 = new DependentObject1();
    private DependentObject2 do2 = new DependentObject2();

    public void setData(String data1, String data2){
        do1.setData(data1);
        do2.setData(data2);
    } 

    public String[] getData(){
        return new String[]{do1.getData(), do2.getData()};
    }
}

class CompositeEntity {
    private CourseGrainedObject cgo = new CourseGrainedObject();
    public void setData(String data1, String data2){
        cgo.setData(data1, data2);
    }
    public String[] getData(){
        return cgo.getData();
    }
}

class Client {
    private CompositeEntity compositeEntity = new CompositeEntity();
    public void printData(){
        for(int i = 0; i < compositeEntity.getData().length; i++){
            System.out.println("Data :"+compositeEntity.getData()[i]);
        }
    }

    public void setData(String data1, String data2){
        compositeEntity.setData(data1, data2);
    }
}

public class CompositeEntityDemo {
    public static void main(String args[]) {
        Client client = new Client();
        client.setData("ram", "shyam");
        client.printData();

        client.setData("ram1", "shyam1");
        client.printData();
    }
}



