<?php
session_start();

include './lib/function.php';
if(check_admin($_SESSION['id']) === FALSE)
{
	header("Location: ./index.php?error");
	exit;
}
?>
<html>
	<head>
		<title>LaBoutik</title>
		<link href='./css/index.css' rel='stylesheet' type='text/css' />
		<link href='./lib/css/font-awesome.min.css' rel='stylesheet' type='text/css' />
	</head>
	<header>
		<nav>
			<ul>
				<br>
				<a href="./"><li id="home">HOME</li></a>
				<div class="menucat">
				<ul class="niveau1 ">
					 <li class="menu01">Categorie<ul class="niveau2">
				<?php
				$conn_sql = mysqli_connect("localhost", "root", "mabite", "rush");
				$get_cat = 'SELECT * FROM `rush`.`category` ';

				$res_cat = mysqli_query($conn_sql, $get_cat);
				if (mysqli_num_rows($res_cat) > 0)
				{
					while (($line_cat = mysqli_fetch_assoc($res_cat)))
					{
						?>
						 <li><a href="category.php?id=<?=$line_cat['id'];?>"><?=$line_cat['cat_name'];?></a></li>
<?php
					}
				}
				mysqli_close($conn_sql);
				?>
							</ul>
						</li>
						</ul>
					</div>
				<?php
					if ((isset($_SESSION['login']) && !empty($_SESSION['login']) && isset($_SESSION['password']) && !empty($_SESSION['password'])))
					{
						echo '<li style="width: 30vw;"><p>Bonjour '.$_SESSION['login'].' !</p></li>';
						echo '<a href="account.php"><li class="menu"><p><i class="fa fa-user"></i> Mon Compte</p></li></a>';
						echo '<a href="basket.php"><li class="menu"><p><i class="fa fa-shopping-basket"></i> Mon panier</p></li></a>';
						if($admin = check_admin($_SESSION['id']) == TRUE)
							echo '<a href="admin.php"><li class="menu"><p><i class="fa fa-sign-in"></i> Administration</p></li></a>';
						echo '<a href="lib/disconnect.php"><li class="menu" style="width: 1vw; text-align: middle;"><p><i class="fa fa-sign-out"></i></p></li></a>';
					}
					else
					{
						echo '<a href="basket.php"><li class="menu"><p><i class="fa fa-shopping-basket"></i> Mon panier</p></li></a>';
						echo '<a href="connect.php"><li class="menu"><p><i class="fa fa-sign-in"></i> Se connecter</p></li></a>';
					}
				?>
			</ul>
		</nav>
	</header>
<left style="text-align:left;">
<form action="./modif_admin.php" method="get">
<td style="width: 10vw; font-size: 2vmin; border:none;">Modifier un User :</td>
<select name="client" id="client" style="visibility:visible; width: 11vw; height: 2vh border:none;">
<?php
	$conn = mysqli_connect("localhost", "root", "mabite");
	$sql = "SELECT * FROM `rush`.`client`";
	$res = mysqli_query($conn, $sql);
	echo '<option value="1">Selectionner un membre</option>';
	while (($line = mysqli_fetch_assoc($res)))
	{
		echo '<option value="'.$line["id"].'">'.$line["name"].'</option>';
	}
?>
</select>
<input type="submit" value="OK">
</form>
<form action="./lib/del_admin.php" method="get">
<td style="width: 10vw; font-size: 2vmin; border:none;">Supprimer un user :</td>
<select name="client" id="client" style="visibility:visible; width: 11vw; height: 2vh border:none;">
<?php
$conn = mysqli_connect("localhost", "root", "mabite");
$sql = "SELECT * FROM `rush`.`client`";
$res = mysqli_query($conn, $sql);
echo '<option value="1">Selectionner un membre</option>';
while (($line = mysqli_fetch_assoc($res)))
{
	echo '<option value="'.$line["id"].'">'.$line["name"].'</option>';
}
?>
</select>
<input type="submit" value="OK">
</form>
<middle style="text-align:center;">
<form action="./lib/add_article.php" method="POST">
<td style="width: 10vw; font-size: 2vmin; border:none;">Ajouter un article :</td>
<td><input type="article" name="name" placeholder="nom de l'article" style="width: 10vw; height: 2vh border:none;"/></td>
<td><input type="article" name="desc" placeholder="description de l'article" style="width: 10vw; height: 2vh border:none;"/></td>
<td><input type="article" name="image" placeholder="lien de l'image de l'article" style="width: 10vw; height: 2vh border:none;"/></td>
<td><input type="article" name="price" placeholder="prix de l'article" style="width: 10vw; height: 2vh border:none;"/></td>
<td><input type="article" name="stock" placeholder="stock disponible" style="width: 10vw; height: 2vh border:none;"/></td>
<select name="cat" id="cat" style="visibility:visible; width: 11vw; height: 2vh border:none;" onkeyup="check();">
<?php
$conn = mysqli_connect("localhost", "root", "mabite");
$sql = "SELECT * FROM `rush`.`category`";
$res = mysqli_query($conn, $sql);
echo '<option value="1">Selectionner une categorie</option>';
while (($line = mysqli_fetch_assoc($res)))
{
	echo '<option value="'.$line["id"].'">'.$line["cat_name"].'</option>';
}
?>
</select>
</select>
<input type="submit" name="filtre_ok" value="OK">
</form>
<form action="./modif_article.php" method="get">
<td style="width: 10vw; font-size: 2vmin; border:none;">Modifier un article :</td>
<select name="articles" id="articles" style="visibility:visible; width: 11vw; height: 2vh border:none;" onkeyup="check();">
<?php
	$conn = mysqli_connect("localhost", "root", "mabite");
	$sql = "SELECT * FROM `rush`.`articles`";
	$res = mysqli_query($conn, $sql);
	echo '<option value="1">Selectionner article</option>';
	while (($line = mysqli_fetch_assoc($res)))
	{
		echo '<option value="'.$line["id"].'">'.$line["name"].'</option>';
	}
?>
</select>
<input type="submit" value="OK">
</form>
<form action="./lib/del_article.php" method="get">
<td style="width: 10vw; font-size: 2vmin; border:none;">Supprimer un article :</td>
<select name="articles" id="articles" style="visibility:visible; width: 11vw; height: 2vh border:none;" onkeyup="check();">
<?php
$conn = mysqli_connect("localhost", "root", "mabite");
$sql = "SELECT * FROM `rush`.`articles`";
$res = mysqli_query($conn, $sql);
echo '<option value="1">Selectionner article</option>';
while (($line = mysqli_fetch_assoc($res)))
{
	echo '<option value="'.$line["id"].'">'.$line["name"].'</option>';
}
?>
</select>
<input type="submit" value="OK"></x>
</form></middle>
<right style="text-align:right;">
<form action="./lib/add_cat.php" method="get">
<td style="width: 10vw; font-size: 2vmin; border:none;">Ajouter categorie :</td>
<td><input type="text" name="categorie" placeholder="nom de la categorie"style="width: 10vw; height: 2vh border:none;"/></td>
</select>
<input type="submit" value="OK">
</form>
<form action="./lib/modif_cat.php" method="post">
<td style="width: 10vw; font-size: 2vmin; border:none;">Modifier categorie :</td>
<select name="categorie_id" id="categorie" style="visibility:visible; width: 11vw; height: 2vh border:none;" onkeyup="check();">
<?php
	$conn = mysqli_connect("localhost", "root", "mabite");
	$sql = "SELECT * FROM `rush`.`category`";
	$res = mysqli_query($conn, $sql);
	echo '<option value="1">Selectionner categorie</option>';
	while (($line = mysqli_fetch_assoc($res)))
	{
		echo '<option value="'.$line["id"].'">'.$line["cat_name"].'</option>';
	}
?>
</select>
<td><input type="text" name="categorie_name" placeholder="Nouveau nom de la categorie" style="width: 10vw; height: 2vh border:none;"/></td>
<input type="submit" value="OK">
</form>
<form action="./lib/del_cat.php" method="get">
<td style="width: 10vw; font-size: 2vmin; border:none;">Supprimer categorie :</td>
<select name="categorie" id="categorie" style="visibility:visible; width: 11vw; height: 2vh border:none;" onkeyup="check();">
<?php
	$conn = mysqli_connect("localhost", "root", "mabite");
	$sql = "SELECT * FROM `rush`.`category`";
	$res = mysqli_query($conn, $sql);
	echo '<option value="1">Selectionner categorie</option>';
	while (($line = mysqli_fetch_assoc($res)))
	{
		echo '<option value="'.$line["id"].'">'.$line["cat_name"].'</option>';
	}
?>
</select>
<input type="submit" name="filtre_ok" value="OK">
</form>
<br>
</right>
</html>
