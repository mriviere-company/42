<?php
	session_start();
	include './function.php';
	if (!isset($_POST['product_id']) || !isset($_POST['chosen_color']))
		header("Location: ./?error=not_added");
  $id = intval($_POST['product_id']);
  $color = htmlspecialchars($_POST['chosen_color'], ENT_QUOTES);
	$conn = mysqli_connect("localhost", "root", "mabite", "rush");
  $qtty = intval($_POST['qtty']);
  $nbpannier = count($_SESSION['panier']);

  if($nbpannier == 0)
  {
    $_SESSION['panier'] = array();
  }

  if(checkConnect() === FALSE)
  {
    $_SESSION['panier'][$nbpannier]["product_id"] = $id;
    $_SESSION['panier'][$nbpannier]["color"] = $color;
    $_SESSION['panier'][$nbpannier]["qtty"] = $qtty;
  	header("Location: ../");
  }
  else
  {
  	$sql = "INSERT INTO `rush`.`user_panier`(`id`, `user_id`, `product_id`, `chosen_color`, `quantitee`, `fact_id`) VALUES (NULL,'".intval($_SESSION['id'])."','".intval($id)."','".htmlspecialchars($color, ENT_QUOTES)."', '".intval($qtty)."', '0')";

  	$res = mysqli_query($conn, $sql);
    $_SESSION['panier'][$nbpannier]["product_id"] = $id;
    $_SESSION['panier'][$nbpannier]["color"] = $color;
    $_SESSION['panier'][$nbpannier]["qtty"] = $qtty;
    $_SESSION['panier'][$nbpannier]["panier_insert_id"] = mysqli_insert_id($conn);
  	mysqli_close($conn);
  	header("Location: ../");
  }
?>
