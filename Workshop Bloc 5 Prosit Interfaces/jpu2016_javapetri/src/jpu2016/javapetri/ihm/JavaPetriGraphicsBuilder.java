package jpu2016.javapetri.ihm;

import jpu2016.javapetri.model.JavaPetri;

import javax.swing.*;
import java.awt.*;
import java.util.Observable;
import java.util.Observer;

public class JavaPetriGraphicsBuilder {
    private final JavaPetri javaPetri;

    public JavaPetriGraphicsBuilder(final JavaPetri javaPetri) {
        this.javaPetri = javaPetri;
    }

    private void clearGraphics(final Graphics graphics) {
        graphics.clearRect(0, 0, this.javaPetri.getWidth() * JavaPetriConsole.EasyFrame.ZOOM, this.javaPetri.getHeight() * JavaPetriConsole.EasyFrame.ZOOM);
    }

    public void applyModelToGraphic(final Graphics graphics) {
        this.clearGraphics(graphics);
        graphics.drawString("Step : " + this.javaPetri.getStep(), 0, 20);
        graphics.drawString("JavaCell alive : " +
                this.javaPetri.getNbJavaCellAlive(), 0, 40);
        graphics.drawString("JavaCell dead : " + this.javaPetri.getNbJavaCellDead(), 0, 60);
    }

    class EasyPanel extends JPanel implements Observer {
        private static final long
                serialVersionUID = 3987064896591403626L;
        private final JavaPetriGraphicsBuilder graphicsBuilder;

        public EasyPanel(final JavaPetriGraphicsBuilder graphicsBuilder) {
            this.graphicsBuilder = graphicsBuilder;
        }

        @Override
        public void update(final Observable arg0, final Object arg1) {
            this.repaint();
        }

        @Override
        protected void paintComponent(final Graphics graphics) {
            this.graphicsBuilder.applyModelToGraphic(graphics);
        }
    }
}
