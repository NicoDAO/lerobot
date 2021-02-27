use IO::Socket::INET;

# auto-flush on socket
$| = 1;
package serveur
	
sub bidule {
    printf "hello"
}

sub tournicote{
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
 
    while (1)
    {
        my $data = "";
        $client_socket->recv($data, 1024);
        print "received data: ->$data<-\n";
        my $posi= 0;
	my $cherche = "voie";
        $posi = index($data, $cherche);	
      	
        if($posi >= 0)
       	    {
      	        print "touvé :\"$cherche\" dans  $data , en position $posi\n";                    
      
	    }
      	# write response data to the connected client
	$data = "recus : ";
	$client_socket->send($data);

        #notify client that response has been sent
       	#shutdown($client_socket, 1);
        }
    }
}
sub ferme {
	$socket->close();
}