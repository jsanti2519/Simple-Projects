import javax.swing.JOptionPane;
/**
@author: Jonathan Santiago
version (1)
Objective: Print Students' information using TextFileInput.java and a text file containing that information.
*/

class Main {
  public static void main(String[] args) {
    Student[] StudentList = new Student[20];

    TextFileInput obj = new TextFileInput("studentnames.txt");

    String line = obj.readLine();
    int i = 0; //loop counter;

    while(line != null) { //is there a neater way to do this???
      StudentList[i].name = line;
      line = obj.readLine();
      StudentList[i].id = Integer.parseInt(line);
      line = obj.readLine();
      StudentList[i].gpa = Double.parseDouble(line);
      line = obj.readLine();
      i++;
    }

    for(int i = 0; i < StudentList.length; i++) //can I type StudentList[j] instead of breaking it down by variables???
      JOptionPane.showMessageDialog(null, StudentList[j].name + "\n" + StudentList[j].id + "\n" + StudentList[j].gpa + "\n");
  } //method main
}
