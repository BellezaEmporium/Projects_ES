package jpu2016.javapetri.ihm;

import jpu2016.javapetri.model.JavaPetri;

import javax.swing.*;
import java.awt.*;
import java.util.Observable;
import java.util.Observer;

public class JavaPetriConsole implements Observer {
    private final JavaPetri javaPetri;
    public JavaPetriConsole(final JavaPetri javaPetri) {
        this.javaPetri = javaPetri;
        javaPetri.addObserver(this);
    }
    private void show() {
        System.out.println(
                "Step : " + this.javaPetri.getStep() + "\tJavaCell alive : " +
                        this.javaPetri.getNbJavaCellAlive() + "\tdead : " + this.javaPetri.getNbJavaCellDead());
    }
    @Override
    public void update(final Observable arg0, final Object arg1) {
        this.show();
    }

    public class EasyFrame extends JFrame {
        private static final long serialVersionUID = -1112124206501543946L;
        public final static int ZOOM =  WIDTH * HEIGHT;

        public EasyFrame(final String title, final JavaPetri javaPetri) {
            this.setTitle(title);
            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            this.setResizable(false);
            this.setVisible(true);
            final EasyPanel easyPanel = new EasyPanel(javaPetri);
            this.setContentPane(easyPanel);
            this.setSize((javaPetri.getWidth() * 5) + this.getInsets().left +
                            this.getInsets().right,
                    (javaPetri.getHeight() * 5) + this.getInsets().top +
                            this.getInsets().bottom);
            this.setLocationRelativeTo(null);
            this.setVisible(true);
            javaPetri.addObserver(easyPanel);
        }
    }
}

class EasyPanel extends JPanel implements Observer {
    private static final long serialVersionUID = 3987064896591403626L;
    private final JavaPetri javaPetri;

    public EasyPanel(final JavaPetri javaPetri) {
        this.javaPetri = javaPetri;
    }
    @Override
    public void update(final Observable arg0, final Object arg1) {
        this.repaint();
    }
    @Override
    protected void paintComponent(final Graphics graphics) {
        graphics.clearRect(0, 0, this.getWidth(), this.getHeight());
        graphics.drawString("Step : " + this.javaPetri.getStep(), 0, 20);
        graphics.drawString("JavaCell alive : " +
                this.javaPetri.getNbJavaCellAlive(), 0, 40);
        graphics.drawString("JavaCell dead : " + this.javaPetri.getNbJavaCellDead(),
                0, 60);
    }
}