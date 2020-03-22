import java.util.*;

class Main {
  public static void main(String[] args) {
    String filename = "studentlist.txt";
    String firstName, lastName;
    double gpa;
    TextFileInput scan = new TextFileInput(filename);
    String line = scan.readLine();
    int i = 0;
    Student[] myArray = new Student[100];
    while(line != null) {
      StringTokenizer foo = new StringTokenizer(line, " ");
      firstName = foo.nextToken();
      lastName = foo.nextToken();
      gpa = Double.parseDouble(foo.nextToken());
      line = scan.readLine();
      myArray[i++] = new Student(firstName, lastName, gpa);
    }

    for(int k = 0; k < i; k++) System.out.println(myArray[k]); //replaced space with " | " between name and GPA
    System.exit(0);
  }
}
