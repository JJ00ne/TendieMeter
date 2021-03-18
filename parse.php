<head><title><?php 
    function get_tag($xml) {


        $tag_regex = '/<span class="QuoteStrip-lastPrice">(.*?)<\/span>/si';

        preg_match($tag_regex, $xml, $matches);
		return $matches[1];
    }

    $yourentirehtml = file_get_contents("https://www.cnbc.com/quotes/GME"); //If you want another ticker, change it here
    $extract = get_tag($yourentirehtml);
    echo $extract;
?></title></head>
<body><?php 
    echo $extract;
?></body>