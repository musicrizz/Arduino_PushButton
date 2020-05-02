# Arduino_PushButton
<p align="center">
It is an utility class for Push-Button, 
<br/>with debouce sistem based on time that is configurable <br/>
Very simple to use with two mode :  <br/> INPUT or INPUT_PULLUP <br/>
You can pass a method() do you prefer to the constructor</br>
</p>

<div id ="example">
<p>
<code>
  Button*  button1 = new Button(PIN_BUTTON_1,  INPUT,  Method_1 );
</code>
<br/>
<code>
  Button*  button2 = new Button(PIN_BUTTON_2,  INPUT_PULLUP,  Method_2 );
</code>
</p>
</div>

<p>
Check the example in the PushButtonExample folder
</p>

<p align="center">
  <img src="pushButton.png"/>
</p>
