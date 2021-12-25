## Project Proposal (damianc2-yifanc23-achyuta2-asrigo2)

1. **Leading Question** We would like to minimize distance between two airports by finding the shortest flight route between them. Second goal would be to make it from one airport to another with the least possible connection flights to minimize the number of stops between two airports. We will also add functionality to include a point of interest, so we have to fly through that airport (eg: want to visit LHR on a trip from JFK to BOM, fly JFK->LHR, LHR->BOM)
2. **Dataset Acquistion and Processing** The dataset we propose is the OpenFlights Dataset. We will focus on the Airports and Routes subset. The Airports subset consists of information such as airport ID, latitude, longtitude, and altitutde within airports.dat. The Routes subset inlcudes airline information, source airport, and number of stops in routes.dat. Then we will extract data from the .dat files using references from [StackOverflow](https://stackoverflow.com/questions/35820879/read-a-dat-file-in-c). Looking at the dataset, we see that there is a lot of excess data that will not be of use to us, therefore once we extract the data, we will clean it up to reduce the amount of data we have to process to only the data that is essential for our project. If the data contains errors like the numbers contains non decimal values, or the airport code is more than the standard IATA format, then we will not take that value into consideration and will have logic to ensure such errors are taken care of.
3. **Graph Algorithms** When traversing through the graph of the various airports obtained from our dataset, we will implement breatdh-first search. These algorthims will be necessary to find the neighboring airports from our travellers origin as well as find the most efficeint route. Some potential inputs these algorthims will take include, current airport ID and desired airport ID. Expected outputs may include a list of cities to visit during the journey.  To obtain the shortest path, we will be using Djikstra's Algorithm (using latitude and longitude values to calculate distance) which will be analagous to the weights of the edges in a graph. Furthermore, one can think of the data as the airports are the vertices, and the edges are the routes from one airport to the other. This way our implementation of BFS should be easy to visualize. The algorthms will take as user input either 2 or 3 Airport Codes (IATA 3 letter codes) and if two are passed then find the shortest route as discussed, and if three are passed then the third parameter will be considered as the point of interest stop enroute. We will be using Force Directed Graph Drawing to output the graph as given our project, we believe it will be the nicest representation of data. This will not have any user input, but is more to do with representation of the entire route options across the world.
4. **Timeline** 

   11/8 - Review proposal and team contract to be submitted 
   
   11/15 - Creating Makefile, initializing the repository, reading in data from file, constructing the graph class and writing test cases
   
   11/29-12/1 - Mid-project checkin: Completing and testing the BFS Traversal
   
   12/4 - Progress of iterative deepening and Dijkstra's algorithm
   
   12/10 - Finishing up the code for the project and sufficiently testing everything
   
   12/11 - Organizing speaking roles and Recording presentation
   
   12/13 - Due date 
