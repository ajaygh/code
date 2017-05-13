//Simulates database

import java.util.List;
import java.util.ArrayList;

public class StudentBo {
    private List<StudentVO> students;

    public StudentBo(){
        students = new ArrayList<>();
        StudentVO student1 = new StudentVO("tom", 0);
        StudentVO student2 = new StudentVO("jack", 1);
        students.add(student1);
        students.add(student2);
    }
    public List<StudentVO> getAllStudents(){
        return students;
    }

    public void updateStudent(StudentVO student){
        students.get(student.getRollNo()).setName("ram");
        System.out.println("Student [ name "+student.getName() + " RollNo "
        + student.getRollNo()+" ] updated in database.");        
    }
    public StudentVO getStudent(int rollNo){
        return students.get(rollNo);
    }
    
    public void deleteStudent(StudentVO student){
        students.remove(student.getRollNo());
        System.out.println("Student [ name "+student.getName() + " RollNo "
        + student.getRollNo()+" ] deleted");
    }
}
