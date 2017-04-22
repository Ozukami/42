import java.util.ArrayList;
import java.util.List;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class DragGroupSample extends Application {

    public static void main( String[] args ) {
        launch();
    }

    // list of nodes that are dragged. Can be modified at any time (on the FX Application Thread):
    private final List<Circle> nodesToDrag = new ArrayList<>();

    private Circle circle1;
    private Circle circle2;
    private Circle circle3;

    private void makeDraggable( Circle circle ) {
        MouseLocation lastMouseLocation = new MouseLocation();

        // --- remember initial coordinates of mouse cursor and node
        circle.addEventFilter( MouseEvent.MOUSE_PRESSED, (
                final MouseEvent mouseEvent ) -> {
            lastMouseLocation.x = mouseEvent.getSceneX() ;
            lastMouseLocation.y = mouseEvent.getSceneY() ;

            // just some example logic to modify the list of dragged nodes:
            boolean found = false ;
                if (circle1 == circle || circle2 == circle || circle3 == circle) found = true ;
                if (found) nodesToDrag.add(circle1);
                if (found) nodesToDrag.add(circle2);
                if (found) nodesToDrag.add(circle3);
        } );

        // --- Shift node calculated from mouse cursor movement
        circle.addEventFilter( MouseEvent.MOUSE_DRAGGED, (
                final MouseEvent mouseEvent ) -> {
                    double deltaX = mouseEvent.getSceneX() - lastMouseLocation.x ;
                    double deltaY = mouseEvent.getSceneY() - lastMouseLocation.y ;
                    for (Circle c : nodesToDrag) {
                        c.setCenterX( c.getCenterX() + deltaX  );
                        c.setCenterY( c.getCenterY() + deltaY );
                    }
                    lastMouseLocation.x = mouseEvent.getSceneX();
                    lastMouseLocation.y = mouseEvent.getSceneY();
        } );

        circle.addEventFilter(MouseEvent.MOUSE_RELEASED, mouseEvent -> nodesToDrag.clear());

    }

    @Override
    public void start( Stage primaryStage ) throws Exception {

        circle1 = new Circle( 30.0, 30.0, 30.0, Color.RED );
        circle2 = new Circle( 45.0, 45.0, 30.0, Color.GREEN );
        circle3 = new Circle( 60.0, 60.0, 30.0, Color.BLUE );

        makeDraggable( circle1 );
        makeDraggable( circle2 );
        makeDraggable( circle3 );

        Group root = new Group();
        root.getChildren().addAll( circle1, circle2, circle3);
        primaryStage.setResizable( false );
        primaryStage.setScene( new Scene( root, 400, 350 ) );
        primaryStage.setTitle( DragGroupSample.class.getSimpleName() );
        primaryStage.show();
    }

    private static final class MouseLocation {
        public double x, y;
    }
}