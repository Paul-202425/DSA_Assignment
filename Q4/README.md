Q4: IoT Gateway Connectivity (BFS)

The objective of the fourth problem was to list the direct (one-hop) neighbours of the selected gateway in the user input. Furthermore, it was necessary to find the one with the highest transfer time.

Methodology:

Input: The first step was to validate the input and ensure that it is a single letter from A to G (case-insensitive).

BFS Algorithm: For the search algorithm itself, the array-based queue was used. To mark the nodes that were visited and measure the shortest distance, a visited array and a distance (dist) array were created. The nodes with the distance from the starting node equal to one were the one-hop gateways.

Highest link: To determine the maximum transfer time among the one-hop nodes, the edges’ weights are being compared.

The following results were obtained for the starting node D:

BFS order: D → A → B → C → E → F → G

One-hop neighbours: A (12), B (5), C (17), E (22), F (15)

Highest transfer time: E (22).
