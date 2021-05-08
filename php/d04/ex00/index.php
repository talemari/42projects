<html>
<header>

<style>
   * {box-sizing: border-box}
   *
   *    /* Add padding to containers */
   .container {
   padding: 16px;
   }

   /* Full-width input fields */
   input[type=text], input[type=password] {
   width: 100%;
   padding: 15px;
   margin: 5px 0 22px 0;
   display: inline-block;
   border: none;
   background: #f1f1f1;
   }

   input[type=text]:focus, input[type=password]:focus {
   background-color: #ddd;
   outline: none;
   }

   /* Overwrite default styles of hr */
   hr {
   border: 1px solid #f1f1f1;
   margin-bottom: 25px;
   }

   /* Set a style for the submit/register button */
   .registerbtn {
   background-color: #4CAF50;
   color: white;
   padding: 16px 20px;
   margin: 8px 0;
   border: none;
   cursor: pointer;
   width: 100%;
   opacity: 0.9;
   }

   .registerbtn:hover {
   opacity:1;
   }

   /* Add a blue text color to links */
   a {
   color: dodgerblue;
   }

   /* Set a grey background color and center the text of the "sign in" section */
   .signin {
   background-color: #f1f1f1;
   text-align: center;
   }
</style>
</header>
<?php
session_start();
if ($_GET['login'] && $_GET['passwd'] && $_GET['submit'] == "OK" && 
	(!$_SESSION['login'] || !$_SESSION['passwd']))
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>
<body>
   <div class="container">
       <h1>Register</h1>
       <p>Please fill in this form to create an account.</p>
	   <hr>
		<form action="index.php">
       <label for="login"><b>Login</b></label>
	   <input type="text" placeholder="Enter Login" name="login" value="<?php echo $_SESSION['login']?>" required>
       <label for="passwd"><b>Password</b></label>
	   <input type="text" placeholder="Enter Password" name="passwd" value="<?php echo $_SESSION['passwd']?>" required>
       <hr>
	   <button type="submit" value="OK" class="registerbtn">Submit</button>
		</form>
   </div>

   <div class="container signin">
   </div>
</body>
</html>
