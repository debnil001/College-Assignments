public class prog5 {
    static class Student{
        int roll;
        String name;
        float score;

        void setScore(float score){
            try{
                if(score < 0 || score > 100){
                    throw new IllegalArgumentException("Score must be between 0 and 100");
                }
                else{
                    this.score = score;
                    System.out.println("Score set to " + this.score);
                }
            }
            catch(IllegalArgumentException e){
                System.out.println("Exception set to " + e.getMessage());
            }
        }
    }
    public static void main(String[] args) {
        Student student = new Student();
        student.setScore(-52);
    }
}
