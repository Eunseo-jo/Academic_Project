function KellerImg() {
    document.getElementById("bigimg").src = "img/keller.jpg";
  }
  
  function MorrillImg() {
    document.getElementById("bigimg").src="img/morrill.jpg";
}

var map, keyword;
    var activeInfoWindow, marker;
    var directionsDisplay, directionsService;
    
    function createMap() {
        directionsService = new google.maps.DirectionsService();
        directionsRenderer = new google.maps.DirectionsRenderer();

        var mapOptions = {
            zoom: 14,
            center: new google.maps.LatLng(44.9727,-93.23540000000003)
        };
        

        var uofM = {lat: 44.9727, lng: -93.23540000000003};
        map = new google.maps.Map(document.getElementById('googleMap'), {
            center: uofM,
            zoom: 14 
        });
        map = new google.maps.Map(document.getElementById('googleMap'), mapOptions);

        var val = parseFloat(document.getElementById("inputRadius").value);
        var type = document.getElementById("place").value;
        if (type=="other") {keyword = document.getElementById('OtherPlace').value;}

        var request = {
            location: map.getCenter(),
            radius: val,
            types: [type]
        }
    
        if (keyword) { request.keyword = [keyword];}
        document.getElementById("place").onchange = function () {
        document.getElementById("OtherPlace").setAttribute("disabled", "disabled");
        if (this.value == 'other')
            document.getElementById("OtherPlace").removeAttribute("disabled");
    };


        geocoder = new google.maps.Geocoder();
        for(i = 0; i < markaddress.length; i ++)
        {
            address = markaddress[i];
            addressTransit(geocoder, map);
        }
    
        var service = new google.maps.places.PlacesService(map);
        service.nearbySearch(request, callback);

        google.maps.event.addDomListener(document.getElementById('findRoute'), 'click', calcRoute);
        
        
        directionsDisplay.setMap(map);
    }



    function addressTransit(geocoder, map) {
        geocoder.geocode({'address': address}, function(results, status) {
          if (status === 'OK') {
            map.setCenter(results[0].geometry.location);
            
            var marker = new google.maps.Marker({
              map: map,
              position: results[0].geometry.location,
            });

            marker.setIcon(({
                url: 'img/marker.png',
                size: new google.maps.Size(71, 71),
                origin: new google.maps.Point(0, 0),
                anchor: new google.maps.Point(17, 34),
                scaledSize: new google.maps.Size(35, 35)
            
            }));
            addInfoWindow(marker, address);
            
          } else {
            alert('Geocode was not successful for the following reason: ' + status);
          }
        });
    }

    function callback(results, status) {
      if (status == google.maps.places.PlacesServiceStatus.OK) {
        console.log(results.length);
        for (var i = 0; i < results.length; i++) {
          createMarker(results[i]);
        }
      }
    }

    function createMarker(place) {
      var placeLoc = place.geometry.location;
      marker = new google.maps.Marker({
        map: map,
        position: place.geometry.location,
    })
        var msg = '<div><strong>' + place.name + '</strong><br>' + place.formatted_address; 
            //not shown place.formatted_address
        addInfoWindow(marker, msg); 
    }

    function addInfoWindow(marker, message) {

        var infoWindow = new google.maps.InfoWindow({
            content: message
        });

        google.maps.event.addListener(marker, 'click', function () {
            infoWindow.open(map, marker);
        });
    } 

    //table information
    const name = [];
    const markaddress = [];
    
    var table = document.getElementById('table1');
    var rowLength = table.rows.length;
    console.log(table);
    var information = new Array(rowLength);
    for (var i = 0; i < information.length; i++) {
        information[i] = new Array(3); //change to 4
    }

    for (i = 1; i < rowLength; i++){
        var Cells = table.rows.item(i).cells;
        var n = Cells.item(0).innerHTML;
        name.push(n);
    }
    
    //make list
    var names = name, selects = document.getElementById("TakeMeTo");
    for(var i = 0; i < names.length; i++){
        selects.options.add(new Option(names[i], names[i]));
    }  
    //save address
    for (i = 1; i < rowLength; i++){
        var Cells = table.rows.item(i).cells;
        var n = Cells.item(2).innerHTML;
        markaddress.push(n);
    }
    //save info
    for (i = 0; i < rowLength; i++){
            var Cells = table.rows.item(i).cells;
    
            information[i][0] = Cells.item(0).innerHTML;
            information[i][1] = Cells.item(2).innerHTML;
            information[i][2] = Cells.item(3).innerHTML;
            
    }
    
    //get current location
        var user_loc = navigator.geolocation;
        var startlat = 44.9727;
        var startlong = -93.23540000000003;

        if(user_loc) {
            user_loc.getCurrentPosition(CurrentPositionData);
            }
        
        function CurrentPositionData(data) {
            startlat = data.coords.latitude;
            startlong = data.coords.longitude;
        }
    //get current location end
    
    //if start different location
    var StartLocationinput = document.getElementById('startLocation');
        if (StartLocationinput){
            google.maps.event.addDomListener(window, 'load', searchLocation);
    
            function searchLocation() {
                var autocomplete = new google.maps.places.Autocomplete(StartLocationinput);
                autocomplete.addListener('place_changed', function () {
                var place = autocomplete.getPlace();
                // place variable will have all the information you are looking for.
                startlat = place.geometry['location'].lat();
                startlong = place.geometry['location'].lng();
            });
        }
    } //if start different location end
    
    
    //Find  lat & lng from address
    var endlat, endlong;
    var geocoder = new google.maps.Geocoder();
    geocoder.geocode( { 'address': address}, function(results, status) {
        var location = results[0].geometry.location;
        endlat = location.lat();
        endlong = location.lng();
    });

      
    
      function initialize() {
        map = new google.maps.Map(document.getElementById('googleMap'), mapOptions);
        directionsService = new google.maps.DirectionsService();
        directionsDisplay = new google.maps.DirectionsRenderer();
        var UofM = new google.maps.LatLng(44.9727,-93.23540000000003);
        var mapOptions = {
          zoom: 14,
          center: UofM
        };
        
        
      }

        endlat = 44.9758682;
        endlong = -93.2324043;

      function calcRoute() {
        var start = new google.maps.LatLng(startlat,startlong);
        var end = new google.maps.LatLng(endlat,endlong);
  
        var method = document.getElementById('method').value;
        var modeType;
        if (document.getElementById('DRIVING').checked) modeType = document.getElementById('DRIVING').value;
        else if (document.getElementById('WALKING').checked) modeType = document.getElementById('WALKING').value;
        else if (document.getElementById('TRANSIT').checked) modeType = document.getElementById('TRANSIT').value;
        var request = {
            origin: start,
          destination: end,
          travelMode: google.maps.TravelMode[modeType]
        };

        directionsService.route(request, function(response, status) {
          if (status == google.maps.DirectionsStatus.OK) {
            directionsDisplay.setDirections(response);
            directionsDisplay.setMap(map);
          } else {
            alert("Directions Request from " + start.toUrlValue(6) + " to " + end.toUrlValue(6) + " failed: " + status);
          }
        });
      }
      
        google.maps.event.addDomListener(window, 'load', initialize);
    


//MyForm
function initFormMap() {
    var map = new google.maps.Map(document.getElementById('googleMap'), {
        center: {lat: 44.9727, lng: -93.23540000000003}, zoom: 14 });
    var input = document.getElementById('location');

    var autocomplete = new google.maps.places.Autocomplete(input);
    var infowindow = new google.maps.InfoWindow();
    var marker = new google.maps.Marker({
        map: map,
    });

    autocomplete.addListener('place_changed', function() {
        infowindow.close();
        marker.setVisible(false);
        var place = autocomplete.getPlace();
    
        if (place.geometry.viewport) {
            map.fitBounds(place.geometry.viewport);
        } else {
            map.setCenter(place.geometry.location);
            map.setZoom(14);
        }
        
        marker.setPosition(place.geometry.location);
        marker.setVisible(true);

    });     
    }

    
    function generateRandomPassword() {
        var string_length = 10;
        var result = "";
        var id = 0;
        var chars = [
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", // letters
        "0123456789", // numbers
        "!%&@#$^*?_~" // symbols
        ];
        for(var i = 0; i < string_length; i++) {
        // id will return 0, 1, 2
        id = Math.floor(Math.random() * 3);
        result += chars[id].charAt(Math.floor(Math.random() * chars[id].length));
        }
        // feel free to change the Element ID
        document.getElementById("randomPassword").value = result;
        }