<?php
include './lib/function.php';

$conn = mysqli_connect("localhost", "root", "mabite");
$adm_pass = passwordify("admin", "admin");

$sql = array(
	"DROP DATABASE IF EXISTS rush",
	"CREATE DATABASE rush"
);

echo "<table style='width: 100%;' border='1px' cellspacing='0'>";
foreach ($sql as $key)
{
	if (mysqli_query($conn, $key) === TRUE)
		echo "<tr><td><code>$key</code></td><td><b style='color: #27ae60; text-align: center;'>SUCCESS</b></td></tr>";
	else
		echo "<tr><td><code>$key</code></td><td><b style='color: #c0392b; text-align: center;'>ERROR</b></td></tr>";
}
//$conn->close();


/* ************************************************************************** */
/*                         INITIALISATION DE LA DB RUSH                       */
/* ************************************************************************** */

//$conn = new mysqli($serv, $user, $pass, "rush");
//if ($conn->connect_error) {
//	die("Connection failed: " . $conn->connect_error);
//}
mysqli_select_db($conn, 'rush');

$sql = array(
	"CREATE TABLE `rush`.`client` ( `id` INT NOT NULL AUTO_INCREMENT , `name` TEXT NOT NULL , `pass` TEXT NOT NULL , `type` INT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;",
	"CREATE TABLE `category` (  `id` int(11) NOT NULL  AUTO_INCREMENT,  `cat_name` text NOT NULL , PRIMARY KEY (`id`)) ENGINE=InnoDB;",
	"CREATE TABLE `rush`.`user_panier` ( `id` int(11) NOT NULL AUTO_INCREMENT,  `user_id` int(11) NOT NULL, `product_id` int(11) NOT NULL,  `chosen_color` text NOT NULL , `quantitee` INT NOT NULL	, PRIMARY KEY (`id`)) ENGINE=InnoDB;",
	"CREATE TABLE `rush`.`articles` ( `id` INT NOT NULL AUTO_INCREMENT , `last_change` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP , `name` TEXT NOT NULL , `description` TEXT NOT NULL , `price` INT NOT NULL , `stock` INT NOT NULL , `category` INT NOT NULL , `colors` MEDIUMTEXT NOT NULL , `img` TEXT NOT NULL  , PRIMARY KEY (`id`)) ENGINE = InnoDB;",
	"INSERT INTO `rush`.`client` (`id`, `name`, `pass`, `type`) VALUES (NULL, 'admin', '$adm_pass', '1')",
	"INSERT INTO `category` (`id`, `cat_name`) VALUES (NULL, 'apple'), (NULL, 'samsung')",
	"INSERT INTO `user_panier` (`id`, `user_id`, `product_id`, `chosen_color`, `quantitee`) VALUES (NULL, '0', '0', 'lol', '0')",
	"INSERT INTO `rush`.`articles`(`id`, `last_change`, `name`, `description`, `price`, `stock`, `category`, `colors`, `img`) VALUES (NULL, CURRENT_TIMESTAMP, 'Iphone 5c', 'Vivez l''expérience Apple avec toute l''intuitivité offerte par iOS et la puce A6 extrêmement économique en énergie. L''appareil photo iSight 8 mégapixels immortalise vos plus beaux moments en photo et vidéo, tandis que son design unique offre légèreté et robustesse.', '220', '20', '1', '[\"noir\",\"blanc\",\"gris\",\"rose\"]', 'apple_iphone_5c_front.jpg')",
	"INSERT INTO `rush`.`articles`(`id`, `last_change`, `name`, `description`, `price`, `stock`, `category`, `colors`, `img`) VALUES (NULL, CURRENT_TIMESTAMP, 'Iphone 5s', 'Une puce avec architecture 64 bits, un capteur d''identité par empreinte digitale, un appareil photo amélioré et plus rapide, un système conçu spécifiquement pour le 64 bits voici les principales nouveautés de l''iPhone 5s.', '330', '20', '1', '[\"noir\",\"blanc\",\"gris\",\"rose\"]', 'apple_iphone_5s.jpg')",
	"INSERT INTO `rush`.`articles`(`id`, `last_change`, `name`, `description`, `price`, `stock`, `category`, `colors`, `img`) VALUES (NULL, CURRENT_TIMESTAMP, 'Iphone 6', 'Plus grand, plus large, plus fin et plus puissant, voilà comment définir l''Apple iPhone 6. Chaque détail, chaque aspect matériel a été méticuleusement pensé et optimisé pour vous offrir le smartphone parfait.', '215', '20', '1', '[\"noir\",\"blanc\",\"gris\",\"rose\"]', 'apple_iphone_6.jpg')",
	"INSERT INTO `rush`.`articles`(`id`, `last_change`, `name`, `description`, `price`, `stock`, `category`, `colors`, `img`) VALUES (NULL, CURRENT_TIMESTAMP, 'Iphone 6s', 'La barre était déjà très haute, mais l''Apple iPhone 6s a surpassé les qualités qui ont fait le succès de la précédente génération. Fabriqué en aluminium 7000 Series, l''alliage le plus solide jamais utilisé pour un iPhone, il présente un écran Retina HD de 4.7&#147; taillé dans le verre le plus solide.', '280', '20', '1', '[\"noir\",\"blanc\",\"gris\",\"rose\"]', 'apple_iphone_6s.jpg')",
	"INSERT INTO `articles` (`id`, `last_change`, `name`, `description`, `price`, `stock`, `category`, `colors`, `img`) VALUES (NULL, CURRENT_TIMESTAMP, 'GALAXY A5', 'Accessible au plus grand nombre, le Samsung Galaxy A5 2016 adopte un design sobre et élégant fait de verre et de métal. Grâce à ses finitions travaillées, sa finesse et son verre Gorilla Glass 4, le Galaxy A5 est un smartphone moderne et soigné.', '150', '20', '2', '[\"noir\",\"blanc\"]', 'a5.jpeg');",
);

foreach ($sql as $key)
{
	if (mysqli_query($conn, $key) === TRUE)
		echo "<tr><td><code>$key</code></td><td><b style='color: #27ae60; text-align: center;'>SUCCESS</b></td></tr>";
	else
		echo "<tr><td><code>$key</code></td><td><b style='color: #c0392b; text-align: center;'>ERROR</b></td></tr>";
}
echo "</table>";
mysqli_close($conn);
?>
