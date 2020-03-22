import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Student[]myArray = new Student[100];

    String f = "", l;
    double g;
    Scanner in = new Scanner(System.in);
    int i = 0; //first loop counter (to gather students' information)
    while(true) {
      System.out.print("Enter student's information:\nFirst Name: ");
      f = in.next();
      if(f.equalsIgnoreCase("STOP")) break;
      System.out.print("Last Name: ");
      l = in.next();
      System.out.print("GPA: ");
      g = in.nextDouble();
      myArray[i++] = new Student(f, l, g);
    }
    int k = 0; //declaration of second loop counter (to output students' information)
    while(k != i) System.out.println(myArray[k++]);
    in.close();
    System.exit(0);
  }
}
