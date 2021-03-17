#!/usr/bin/perl 

use IO::Socket::INET;

use Commande;
#export PERL5LIB=~/robot/logiciel/lerobot

# auto-flush on socket
$| = 1;

# creating a listening socket
my $socket = new IO::Socket::INET (
    LocalHost => '0.0.0.0',
    LocalPort => '7777',
    Proto => 'tcp',
    Listen => 5,
    Reuse => 1
);
die "cannot create socket $!\n" unless $socket;
print "server waiting for client connection on port 7777\n";

while(1)
{
	# waiting for a new client connection
	my $client_socket = $socket->accept();

	# get information about a newly connected client
	my $client_address = $client_socket->peerhost();
	my $client_port = $client_socket->peerport();
	print "connection from $client_address:$client_port\n";

	# read up to 1024 characters from the connected client

	$objet_commande = new Commande( "avance");
	$objet_commande1 = new Commande( "recule");
	$objet_commande2 = new Commande( "avantdroite");
	$objet_commande3 = new Commande( "avantgauche");
	$objet_commande4 = new Commande( "arrieredroite");
	$objet_commande5 = new Commande( "arrieregauche");
	$objet_commande6 = new Commande( "arret");
	$objet_commande7 = new Commande( "telemetrie");


	
	while (1)
	{
		my $data = "";
		my $retour1 = "";
		my $retour2 = "";
		my $retour3 = "";
		my $retour4 = "";
		my $retour5 = "";
		my $retour6 = "";
		$client_socket->recv($data, 1024);
		print "received data: ->$data<-\n";
		
		$retour1= $objet_commande->traiteCommande($data);
		$retour2= $objet_commande1->traiteCommande($data);
	        $retour3= $objet_commande2->traiteCommande($data);
		$retour4= $objet_commande3->traiteCommande($data);
		$retour5= $objet_commande4->traiteCommande($data);
		$retour6= $objet_commande5->traiteCommande($data);
		#$objet_commande7->traiteCommande($data);

		
		# write response data to the connected client
		
		#$data = "$objet_commande->retour $objet_commande1->retour $objet_commande2->retour $objet_commande3->retour $objet_commande4->retour $objet_commande5->retour  $objet_commande6->retour";
		#$data = $objet_commande->retour;
						
		#$client_socket->send($objet_commande->retour);
		$client_socket->send("avance $retour1 \n");
		$client_socket->send("recule $retour2 \n");
		$client_socket->send("avantdroite $retour3 \n");
		$client_socket->send("avantgauche $retour4 \n");
		$client_socket->send("arriere droite $retour5 \n");
		$client_socket->send("arriere gauche $retour6 \n\n");

		#notify client that response has been sent
		#shutdown($client_socket, 1);
	}
}

sub ferme {
$socket->close();
}
