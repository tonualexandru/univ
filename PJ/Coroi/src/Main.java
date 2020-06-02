import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class Main extends JFrame {
    private JPanel mainPane;
    private JButton btnAdd;
    private JButton btnRemove;
    private JLabel msg;
    private JLabel count;
    private JComboBox comboBox1;

    private int counter = 1;

    public Main(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPane);
        this.pack();
        btnAdd.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("add");
                if(counter == 10) {
                    msg.setText("Can not increment");
                }
                else {
                    count.setText(String.valueOf(++counter));
                }
            }
        });
        btnRemove.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("remove");
                if(counter == 1) {
                    msg.setText("Can not decrement");
                }
                else {
                    count.setText(String.valueOf(--counter));
                }
            }
        });

        Random ran = new Random();
        int radius = ran.nextInt(26);
        if(radius < 20)
            radius = 20 + radius % 20;

        comboBox1.addItem(25);
        comboBox1.addItem(radius);
    }


    public static void main(String[] args) {
        JFrame frame = new Main("Circles");
        frame.setVisible(true);
        frame.setSize(400, 300);
    }

}


