class Student {
  private String firstName, lastName;
  private double gpa;

  public Student(String f, String l, double grade) {
    firstName = f;
    lastName = l;
    gpa = grade;
  }
  public void setFirst(String f) {
    firstName = f;
  }
  public void setLast(String l) {
    lastName = l;
  }
  public void setGPA(double g) {
    gpa = g;
  }

  public String getFirst() {
    return firstName;
  }
  public String getLast() {
    return lastName;
  }
  public double getGPA() {
    return gpa;
  }

  public String toString() {
    return firstName + " " + lastName + " | " + gpa;
  }
}
