
import java.util.LinkedList;
import java.util.Scanner;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class main extends Application {

    public static void main(String[] args) {
        Application.launch(main.class, args);
    }
    
    @Override
    public void start(Stage primaryStage) {
    	int	i = 0;
    	int ant = 0;
    	String line;
    	String split[];
    	LinkedList<Room> roomList = new LinkedList<Room>();
    	Scanner sc = new Scanner(System.in);
    	while (sc.hasNext())
    	{
    		if (i++ == 0)
    			ant = sc.nextInt();
    		else
    		{
    			line = sc.nextLine();
    			if (!(line.startsWith("#")) && line.contains(" "))
    			{
    				split = line.split(" ");
    				roomList.add(new Room(split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2])));
    			}
    		}
    	}    	
    	roomList.forEach(elem -> {
    		System.out.printf("%d %s %d %d\n", elem.getId(), elem.getName(), elem.getX(), elem.getY());
    	});
    	System.out.printf("\nAnt = %d\n", ant);
        primaryStage.setTitle("Title");
        Group root = new Group();
        Scene scene = new Scene(root, 300, 250, Color.GREY);
        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
                if (event.getCode() == KeyCode.ESCAPE)
                		System.exit(0);
                else
                	System.out.println(event.getCharacter());
            }
        });
        primaryStage.setScene(scene);
        primaryStage.show();
        sc.close();
    }
}