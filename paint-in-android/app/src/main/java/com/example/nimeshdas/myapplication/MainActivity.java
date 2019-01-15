package com.example.nimeshdas.myapplication;

import android.graphics.drawable.Drawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutCompat;
import android.text.style.ForegroundColorSpan;
import android.util.AttributeSet;
import android.view.View;
import android.graphics.Rect;
import android.graphics.RectF;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.view.TouchDelegate;
import android.graphics.Path;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import android.content.Context;
import android.annotation.SuppressLint;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import 	android.view.MotionEvent;
import android.view.LayoutInflater;

import org.w3c.dom.Text;


public class MainActivity extends AppCompatActivity {

    SampleView customView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(new SampleView(this));
        setContentView(R.layout.activity_main);
        customView = new SampleView(this.getBaseContext());
        View Panel = findViewById(R.id.panel);
        LinearLayout l = (LinearLayout)findViewById(R.id.main);
        l.addView(customView);

        Panel.post(new Runnable() {
            // Post in the parent's message queue to make sure the parent
            @Override
            public void run() {
                // The bounds for the delegate view (an ImageButton
                // in this example)
                Rect delegateArea = new Rect();

                // Main buttons
                ImageButton selection_tool = (ImageButton)findViewById(R.id.imageButton);
                ImageButton erase_tool = (ImageButton)findViewById(R.id.imageButton2);
                ImageButton rectangle_tool = (ImageButton)findViewById(R.id.imageButton3);
                ImageButton circle_tool = (ImageButton)findViewById(R.id.imageButton4);
                ImageButton line_tool = (ImageButton)findViewById(R.id.imageButton5);
                ImageButton fill_tool = (ImageButton)findViewById(R.id.imageButton5half);
                final TextView cur_color_tool = (TextView)findViewById(R.id.textButton6);
                ImageButton red_tool = (ImageButton)findViewById(R.id.imageButton7);
                ImageButton green_tool = (ImageButton)findViewById(R.id.imageButton8);
                ImageButton blue_tool = (ImageButton)findViewById(R.id.imageButton9);

                // Thickness of stroke
                ImageButton thinnest = (ImageButton)findViewById(R.id.imageButton11);
                ImageButton thicker = (ImageButton)findViewById(R.id.imageButton12);
                ImageButton secondthickest = (ImageButton)findViewById(R.id.imageButton13);
                ImageButton thickest = (ImageButton)findViewById(R.id.imageButton14);

                selection_tool.setEnabled(true);
                erase_tool.setEnabled(true);
                rectangle_tool.setEnabled(true);
                circle_tool.setEnabled(true);
                line_tool.setEnabled(true);
                fill_tool.setEnabled(true);
                cur_color_tool.setEnabled(true);
                red_tool.setEnabled(true);
                green_tool.setEnabled(true);
                blue_tool.setEnabled(true);

                thinnest.setEnabled(true);
                thicker.setEnabled(true);
                secondthickest.setEnabled(true);
                thickest.setEnabled(true);


                selection_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within selection tool region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_icon("Selection");
                    }
                });

                erase_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within erase tool region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_icon("Erase");
                    }
                });

                rectangle_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within rectangle tool region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_icon("Rectangle");
                    }
                });


                circle_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within circle tool region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_icon("Circle");
                    }
                });

                line_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within line tool region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_icon("Line");
                    }
                });

                fill_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within fill tool region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_icon("Fill");
                        //customView.set_is_filled(true);
                    }
                });

                red_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within red tool touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_color("Red");
                        cur_color_tool.setText("Red");

                    }
                });

                green_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within green tool touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_color("Green");
                        cur_color_tool.setText("Green");
                    }
                });

                blue_tool.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within blue tool touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.update_selected_color("Blue");
                        cur_color_tool.setText("Blue");
                    }
                });

                thinnest.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within thinnest touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.updated_selected_stroke(1);
                    }
                });

                thicker.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within thicker touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.updated_selected_stroke(2);
                    }
                });

                secondthickest.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within secondthickest touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.updated_selected_stroke(3);
                    }
                });

                thickest.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Toast.makeText(MainActivity.this,
                                "Touch occurred within thickest touch region.",
                                Toast.LENGTH_SHORT).show();
                        customView.updated_selected_stroke(4);
                    }
                });

                // The hit Rect for the ImageButton
                thinnest.getHitRect(delegateArea);
                thicker.getHitRect(delegateArea);
                secondthickest.getHitRect(delegateArea);
                thickest.getHitRect(delegateArea);

                // Extend the touch area of the ImageButton beyond its bounds
                // on the right and bottom.
                delegateArea.right += 100;
                delegateArea.bottom += 100;
                delegateArea.top += 100;
                delegateArea.left += 100;

                // Instantiate a TouchDelegate.
                // "delegateArea" is the bounds in local coordinates of
                // the containing view to be mapped to the delegate view.
                // "myButton" is the child view that should receive motion
                // events.
                TouchDelegate touchDelegate = new TouchDelegate(delegateArea,
                        thinnest);
                TouchDelegate touchDelegate2 = new TouchDelegate(delegateArea,
                        thicker);
                TouchDelegate touchDelegate3 = new TouchDelegate(delegateArea,
                        secondthickest);
                TouchDelegate touchDelegate4 = new TouchDelegate(delegateArea,
                        thickest);

                // Sets the TouchDelegate on the parent view, such that touches
                // within the touch delegate bounds are routed to the child.
                if (View.class.isInstance(thinnest.getParent())) {
                    ((View) thinnest.getParent()).setTouchDelegate(touchDelegate);
                }
                if (View.class.isInstance(thicker.getParent())) {
                    ((View) thicker.getParent()).setTouchDelegate(touchDelegate2);
                }
                if (View.class.isInstance(thicker.getParent())) {
                    ((View) secondthickest.getParent()).setTouchDelegate(touchDelegate3);
                }
                if (View.class.isInstance(thickest.getParent())) {
                    ((View) thickest.getParent()).setTouchDelegate(touchDelegate4);
                }
            }
        });

    }

}
