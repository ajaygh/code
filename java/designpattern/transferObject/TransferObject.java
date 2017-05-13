//Transfer object pattern demo
public class TransferObject {
    public static void main(String args[]) {
        StudentBo studentBo = new StudentBo();
        
        //get all the students
        for(StudentVO student : studentBo.getAllStudents()){
            System.out.println("Student [ " + "Name : " + student.getName()
            + " Rollno : " + student.getRollNo() + " ]");
        }

        //update a student
        StudentVO student1 = studentBo.getStudent(0);
        student1.setName("tim");
        studentBo.updateStudent(student1);
        student1 = studentBo.getStudent(0);
        System.out.println("Student [ " + "Name : " + student1.getName()
            + " Rollno : " + student1.getRollNo() + " ]");
    }
}
