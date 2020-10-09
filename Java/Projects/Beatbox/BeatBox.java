package Beatbox;

import java.awt.*;
import javax.swing.*;
import javax.sound.midi.*;
import java.util.*;
import java.awt.event.*;
import java.io.*;

public class BeatBox {
  JPanel mainPanel;
  ArrayList<JCheckBox> checkboxList;
  Sequencer sequencer;
  Sequence sequence;
  Track track;
  JFrame theFrame;
  String[] instrumentNames = { "Bass Drum", "Closed Hi-Hat", "Open Hi-Hat", "Acoustic Snare", "Crash Cymbal",
      "Hand Clap", "High Tom", "Hi Bongo", "Maracas", "Whistle", "Low Conga", "Cowbell", "Vibraslap", "Low-mid Tom",
      "High Agogo", "Open Hi Conga" };
  int[] instruments = { 35, 42, 46, 38, 49, 39, 50, 60, 70, 72, 64, 56, 58, 47, 67, 63 };

  public static void main(String[] args) {
    new BeatBox().buildGUI();
  }

  public void buildGUI() {
    theFrame = new JFrame("Cyber BeatBox");
    theFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    BorderLayout layout = new BorderLayout();
    JPanel background = new JPanel(layout);
    background.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
    checkboxList = new ArrayList<JCheckBox>();
    Box buttonBox = new Box(BoxLayout.Y_AXIS);
    JButton start = new JButton("Start");
    start.addActionListener(new MyStartListener());
    buttonBox.add(start);

    JButton stop = new JButton("Stop");
    stop.addActionListener(new MyStopListener());
    buttonBox.add(stop);
    JButton upTempo = new JButton("Tempo Up");
    upTempo.addActionListener(new MyUpTempoListener());
    buttonBox.add(upTempo);
    JButton downTempo = new JButton("Tempo Down");
    downTempo.addActionListener(new MyDownTempoListener());
    buttonBox.add(downTempo);

    JButton SaveBeat = new JButton("Save");
    SaveBeat.addActionListener(new MySendListener());
    buttonBox.add(SaveBeat);

    JButton LoadBeat = new JButton("Load");
    LoadBeat.addActionListener(new MyReadInListener());
    buttonBox.add(LoadBeat);

    Box nameBox = new Box(BoxLayout.Y_AXIS);
    for (int i = 0; i < 16; i++) {
      nameBox.add(new Label(instrumentNames[i]));
    }

    background.add(BorderLayout.EAST, buttonBox);
    background.add(BorderLayout.WEST, nameBox);
    theFrame.getContentPane().add(background);

    GridLayout grid = new GridLayout(16, 16);
    grid.setVgap(1);
    grid.setHgap(2);
    mainPanel = new JPanel(grid);
    background.add(BorderLayout.CENTER, mainPanel);
    for (int i = 0; i < 256; i++) {
      JCheckBox c = new JCheckBox();
      c.setSelected(false);
      checkboxList.add(c);
      mainPanel.add(c);
    } // end loop

    setUpMidi();
    theFrame.setBounds(50, 50, 300, 300);
    theFrame.pack();
    theFrame.setVisible(true);

  } // close method

  public void setUpMidi() {
    try {
      sequencer = MidiSystem.getSequencer();
      sequencer.open();
      sequence = new Sequence(Sequence.PPQ, 4);
      track = sequence.createTrack();
      sequencer.setTempoInBPM(120);

    } catch (Exception e) {
      e.printStackTrace();
    }
  } // close method

  public void buildTrackAndStart() {
    int[] trackList = null;

    sequence.deleteTrack(track);
    track = sequence.createTrack();
    for (int i = 0; i < 16; i++) {
      trackList = new int[16];
      int key = instruments[i];
      for (int j = 0; j < 16; j++) {

        JCheckBox jc = (JCheckBox) checkboxList.get(j + (16 * i));
        if (jc.isSelected()) {
          trackList[j] = key;
        } else {
          trackList[j] = 0;
        }
      } // close inner loop

      makeTracks(trackList);
      track.add(makeEvent(176, 1, 127, 0, 16));
    } // close outer
    track.add(makeEvent(192, 9, 1, 0, 15));
    try {
      sequencer.setSequence(sequence);
      sequencer.setLoopCount(sequencer.LOOP_CONTINUOUSLY);
      sequencer.start();
      sequencer.setTempoInBPM(120);
    } catch (Exception e) {
      e.printStackTrace();
    }
  } // close buildTrackAndStart method

  public class MyStartListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      buildTrackAndStart();
    }
  } // close inner class

  public class MyStopListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      sequencer.stop();
    }
  } // close inner class

  public class MyUpTempoListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      float tempoFactor = sequencer.getTempoFactor();
      sequencer.setTempoFactor((float) (tempoFactor * 1.03));
    }
  } // close inner class

  public class MyDownTempoListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      float tempoFactor = sequencer.getTempoFactor();
      sequencer.setTempoFactor((float) (tempoFactor * .97));
    }
  } // close inner class

  public class MySendListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
      boolean[] checkboxState = new boolean[256];
      for (int i = 0; i < 256; i++) {
        JCheckBox check = (JCheckBox) checkboxList.get(i);
        if (check.isSelected()) {
          checkboxState[i] = true;
        }
      }
      try {
        FileOutputStream fileStream = new FileOutputStream(new File("Checkbox.ser"));
        ObjectOutputStream os = new ObjectOutputStream(fileStream);
        os.writeObject(checkboxState);
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } // close method
  }

  public class MyReadInListener implements ActionListener {
    public void actionPerformed(ActionEvent a) {
    boolean[] checkboxState = null;
    try {
    FileInputStream fileIn = new FileInputStream(new File("Checkbox.ser"));
    ObjectInputStream is = new ObjectInputStream(fileIn);
    checkboxState = (boolean[]) is.readObject();
   
    } catch(Exception ex) {ex.printStackTrace();}
    for (int i = 0; i < 256; i++) {
    JCheckBox check = (JCheckBox) checkboxList.get(i);
    if (checkboxState[i]) {
    check.setSelected(true);
    } else {
    check.setSelected(false);
    }
    }
    sequencer.stop();
    buildTrackAndStart();
    } // close method
    } // close inner class

  public void makeTracks(int[] list) {

    for (int i = 0; i < 16; i++) {
      int key = list[i];
      if (key != 0) {
        track.add(makeEvent(144, 9, key, 100, i));
        track.add(makeEvent(128, 9, key, 100, i + 1));
      }
    }
  }

  public MidiEvent makeEvent(int comd, int chan, int one, int two, int tick) {
    MidiEvent event = null;
    try {
      ShortMessage a = new ShortMessage();
      a.setMessage(comd, chan, one, two);
      event = new MidiEvent(a, tick);
    } catch (Exception e) {
      e.printStackTrace();
    }
    return event;
  }
} // close class
