package rs.raf.predmeti;

import javafx.application.Application;
import javafx.stage.Stage;
import rs.raf.predmeti.view.ObavezniProzor;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        Utils.ucitajPredmete();
        new ObavezniProzor().show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}