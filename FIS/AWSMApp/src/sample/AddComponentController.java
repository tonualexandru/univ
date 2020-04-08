package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class AddComponentController {

    private void gotoHome(ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("homeScene.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }
}
