# GraphMat

Matrix implemented as a graph, specially for the use case when it should be auto expanding at custom rate, specially in simulations.
A matrix header-only library, uses graphs internally, helpful when your matrix is part of a simulation where it needs to grow many times (or just automatically keep growing).

Tip: Can directly go to the documentaion in the wiki section for usage

This was originally a subproject for the worldline project (a catchy name, but an interesting small simulator for me)
So this is still in development, to make it more general, though as of now, it should work for most templated versions, following the needs (for example you need to overload the << operator for std::ostream for display function to work)

## Purpose -

I needed a matrix like data structure, that can have
1. Expansion and deletetion capabilities like that of a list (ie. no need to copy again and again for expansion as in std::vector (and i am not talking about the capacity vs size here, that would not work for my purpose))

2. access as a vector 2x2 matrix, or atleast fast access

Then, i had read somewhere, _A matrix is inherently a graph, each node connected to 4 adjacent nodes_, though it maybe very simple, but quite intutive it seems.

So, now the point of it, So i created a matrix data structure, based on a graph, that completes the requirements for `point 1 above`, though it doesn't have constant time lookups like std::vector, but for my case, i chose to create it like this.

# Documentation
Documentation is being maintained in `wiki` section of this repo.

https://github.com/adi-g15/graphMat/wiki/Graph-Matrix-3D

# Note -
You can likely just use a std::list<std::list<std::list>>, though then memory allocations will be for each node individually, and also i wanted a better structure according to the needs of worldLine Simulation project, auto expansion being one.
Also, in case of `vector<vector<vector<>>>`, you will likely have it grow in ONLY TWO DIRECTIONS, and I WANTED IT TO GROW EQUALLY IN ALL FOUR DIRECTIONS, now this would, almost always mean, that even for a simple expansion, the `vector<vector<vector<>>>` has to completely allocate to a whole new place

© Aditya Gupta 2021
