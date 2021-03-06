#include <float.h>
#include <assert.h>
#include "meshEdit.h"
#include "mutablePriorityQueue.h"
#include "error_dialog.h"

namespace CMU462 {

VertexIter HalfedgeMesh::splitEdge(EdgeIter e0) {
  // TODO: (meshEdit)
  // This method should split the given edge and return an iterator to the
  // newly inserted vertex. The halfedge of this vertex should point along
  // the edge that was split, rather than the new edges.
		
  //showError("splitEdge() not implemented.");
	

	HalfedgeIter h0 = e0->halfedge();
	HalfedgeIter h3 = h0->twin();
	HalfedgeIter h1 = h0->next();
	HalfedgeIter h2 = h1->next();
	HalfedgeIter h4 = h3->next();
	HalfedgeIter h5 = h4->next();
	
	//Faces 
	FaceIter f0 = h0->face();
	FaceIter f1 = h3->face();


	//Vertices
	VertexIter v0 = h0->vertex();
	VertexIter v1 = h3->vertex();
	VertexIter v2 = h2->vertex();
	VertexIter v3 = h5->vertex();

	//Edge
	EdgeIter e1 = h1->edge();
	EdgeIter e2 = h2->edge();
	EdgeIter e3 = h4->edge();
	EdgeIter e4 = h5->edge();

	HalfedgeIter h10 = newHalfedge();
	HalfedgeIter h11 = newHalfedge();
	HalfedgeIter h12 = newHalfedge();
	HalfedgeIter h13 = newHalfedge();
	HalfedgeIter h14 = newHalfedge();
	HalfedgeIter h15 = newHalfedge();

	FaceIter f2 = newFace();
	FaceIter f3 = newFace();

	EdgeIter e11 = newEdge();
	EdgeIter e12 = newEdge();
	EdgeIter e13 = newEdge();

	VertexIter v4 = newVertex();
	
	//Halfedges
	h0->next() = h10;
	h0->twin() = h3;
	h0->vertex() = v0;
	h0->edge() = e0; 
	h0->face() = f0;

	h1->next() = h12;
	h1->vertex() = v1;
	h1->edge() = e1;
	h1->face() = f2;

	h2->next() = h0;
	h2->vertex() = v2;
	h2->edge() = e2;
	h2->face() = f0;

	h3->next() = h4;
	h3->twin() = h0;
	h3->vertex() = v4;
	h3->edge() = e0;
	h3->face() = f1;

	h4->next() = h13;
	h4->vertex() = v0;
	h4->edge() = e3;
	h4->face() = f1;

	h5->next() = h14;
	h5->vertex() = v3;
	h5->edge() = e4;
	h5->face() = f3;

	h10->next() = h2;
	h10->twin() = h12;
	h10->vertex() = v4;
	h10->edge() = e11;
	h10->face() = f0;

	h11->next() = h1;
	h11->twin() = h14;
	h11->vertex() = v4;
	h11->edge() = e13;
	h11->face() = f2;

	h12->next() = h11;
	h12->twin() = h10;
	h12->vertex() = v2;
	h12->edge() = e11;
	h12->face() = f2;

	h13->next() = h3;
	h13->twin() = h15;
	h13->vertex() = v3;
	h13->edge() = e12;
	h13->face() = f1;

	h14->next() = h15;
	h14->twin() = h11;
	h14->vertex() = v1;
	h14->edge() = e13;
	h14->face() = f3;

	h15->next() = h5;
	h15->twin() = h13;
	h15->vertex() = v4; 
	h15->edge() = e12;
	h15->face() = f3;

	//Vertices
	v0->halfedge() = h0;
	v1->halfedge() = h1;
	v2->halfedge() = h2;
	v3->halfedge() = h5;
	v4->halfedge() = h3;

	//Edges
	e0->halfedge() = h0;
	e1->halfedge() = h1;
	e2->halfedge() = h2;
	e3->halfedge() = h4;
	e4->halfedge() = h5;
	e11->halfedge() = h10;
	e12->halfedge() = h13;
	e13->halfedge() = h11;

	//Faces
	f0->halfedge() = h0;
	f1->halfedge() = h3;
	f2->halfedge() = h1;
	f3->halfedge() = h5;

	return v4;
}

VertexIter HalfedgeMesh::collapseEdge(EdgeIter e) {
  // TODO: (meshEdit)
  // This method should collapse the given edge and return an iterator to
  // the new vertex created by the collapse.

  showError("collapseEdge() not implemented.");
  return VertexIter();
}

VertexIter HalfedgeMesh::collapseFace(FaceIter f) {
  // TODO: (meshEdit)
  // This method should collapse the given face and return an iterator to
  // the new vertex created by the collapse.
  showError("collapseFace() not implemented.");
  return VertexIter();
}

FaceIter HalfedgeMesh::eraseVertex(VertexIter v) {
  // TODO: (meshEdit)
  // This method should replace the given vertex and all its neighboring
  // edges and faces with a single face, returning the new face.

  return FaceIter();
}

FaceIter HalfedgeMesh::eraseEdge(EdgeIter e) {
  // TODO: (meshEdit)
  // This method should erase the given edge and return an iterator to the
  // merged face.

  showError("eraseVertex() not implemented.");
  return FaceIter();
}

EdgeIter HalfedgeMesh::flipEdge(EdgeIter e0) {
  // TODO: (meshEdit)
  // This method should flip the given edge and return an iterator to the
  // flipped edge.

	if (e0->isBoundary())
	{
		return e0;
	}

	else
	{

		// HALFEDGES
		HalfedgeIter h0 = e0->halfedge();
		HalfedgeIter h1 = h0->next();
		HalfedgeIter h2 = h1->next();
		HalfedgeIter h3 = h0->twin();
		HalfedgeIter h4 = h3->next();
		HalfedgeIter h5 = h4->next();
		HalfedgeIter h6 = h1->twin();
		HalfedgeIter h7 = h2->twin();
		HalfedgeIter h8 = h4->twin();
		HalfedgeIter h9 = h5->twin();

		// VERTICES
		VertexIter v0 = h0->vertex();
		VertexIter v1 = h3->vertex();
		VertexIter v2 = h5->vertex();
		VertexIter v3 = h2->vertex();

		// EDGES
		EdgeIter e1 = h5->edge();
		EdgeIter e2 = h4->edge();
		EdgeIter e3 = h2->edge();
		EdgeIter e4 = h1->edge();

		// FACES
		FaceIter f0 = h0->face();
		FaceIter f1 = h3->face();

		// Reassigning 

		// HALFEDGES
		h0->next() = h1;
		h0->twin() = h3;
		h0->vertex() = v2;
		h0->edge() = e0;
		h0->face() = f0;

		h1->next() = h2;
		h1->twin() = h7;
		h1->vertex() = v3;
		h1->edge() = e3;
		h1->face() = f0;

		h2->next() = h0;
		h2->twin() = h8;
		h2->vertex() = v0;
		h2->edge() = e2;
		h2->face() = f0;

		h3->next() = h4;
		h3->twin() = h0;
		h3->vertex() = v3;
		h3->edge() = e0;
		h3->face() = f1;

		h4->next() = h5;
		h4->twin() = h9;
		h4->vertex() = v2;
		h4->edge() = e1;
		h4->face() = f1;

		h5->next() = h3;
		h5->twin() = h6;
		h5->vertex() = v1;
		h5->edge() = e4;
		h5->face() = f1;

		h6->next() = h6->next();
		h6->twin() = h5;
		h6->vertex() = v3;
		h6->edge() = e4;
		h6->face() = h6->face();

		h7->next() = h7->next();
		h7->twin() = h1;
		h7->vertex() = v0;
		h7->edge() = e3;
		h7->face() = h7->face();

		h8->next() = h8->next();
		h8->twin() = h2;
		h8->vertex() = v2;
		h8->edge() = e2;
		h8->face() = h8->face();

		h9->next() = h9->next();
		h9->twin() = h4;
		h9->vertex() = v1;
		h9->edge() = e1;
		h9->face() = h9->face();

		// VERTICES
		v0->halfedge() = h2;
		v1->halfedge() = h5;
		v2->halfedge() = h4;
		v3->halfedge() = h3;

		// EDGES
		e0->halfedge() = h0;
		e1->halfedge() = h4;
		e2->halfedge() = h2;
		e3->halfedge() = h1;
		e4->halfedge() = h5;

		// FACES
		f0->halfedge() = h0;
		f1->halfedge() = h3;

		return e0;
	}
}

void HalfedgeMesh::subdivideQuad(bool useCatmullClark) {
  // Unlike the local mesh operations (like bevel or edge flip), we will perform
  // subdivision by splitting *all* faces into quads "simultaneously."  Rather
  // than operating directly on the halfedge data structure (which as you've
  // seen
  // is quite difficult to maintain!) we are going to do something a bit nicer:
  //
  //    1. Create a raw list of vertex positions and faces (rather than a full-
  //       blown halfedge mesh).
  //
  //    2. Build a new halfedge mesh from these lists, replacing the old one.
  //
  // Sometimes rebuilding a data structure from scratch is simpler (and even
  // more
  // efficient) than incrementally modifying the existing one.  These steps are
  // detailed below.

  // TODO Step I: Compute the vertex positions for the subdivided mesh.  Here
  // we're
  // going to do something a little bit strange: since we will have one vertex
  // in
  // the subdivided mesh for each vertex, edge, and face in the original mesh,
  // we
  // can nicely store the new vertex *positions* as attributes on vertices,
  // edges,
  // and faces of the original mesh.  These positions can then be conveniently
  // copied into the new, subdivided mesh.
  // [See subroutines for actual "TODO"s]
  if (useCatmullClark) {
    computeCatmullClarkPositions();
  } else {
    computeLinearSubdivisionPositions();
  }

  // TODO Step II: Assign a unique index (starting at 0) to each vertex, edge,
  // and
  // face in the original mesh.  These indices will be the indices of the
  // vertices
  // in the new (subdivided mesh).  They do not have to be assigned in any
  // particular
  // order, so long as no index is shared by more than one mesh element, and the
  // total number of indices is equal to V+E+F, i.e., the total number of
  // vertices
  // plus edges plus faces in the original mesh.  Basically we just need a
  // one-to-one
  // mapping between original mesh elements and subdivided mesh vertices.
  // [See subroutine for actual "TODO"s]
  assignSubdivisionIndices();

  // TODO Step III: Build a list of quads in the new (subdivided) mesh, as
  // tuples of
  // the element indices defined above.  In other words, each new quad should be
  // of
  // the form (i,j,k,l), where i,j,k and l are four of the indices stored on our
  // original mesh elements.  Note that it is essential to get the orientation
  // right
  // here: (i,j,k,l) is not the same as (l,k,j,i).  Indices of new faces should
  // circulate in the same direction as old faces (think about the right-hand
  // rule).
  // [See subroutines for actual "TODO"s]
  vector<vector<Index> > subDFaces;
  vector<Vector3D> subDVertices;
  buildSubdivisionFaceList(subDFaces);
  buildSubdivisionVertexList(subDVertices);

  // TODO Step IV: Pass the list of vertices and quads to a routine that clears
  // the
  // internal data for this halfedge mesh, and builds new halfedge data from
  // scratch,
  // using the two lists.
  rebuild(subDFaces, subDVertices);
}

/**
 * Compute new vertex positions for a mesh that splits each polygon
 * into quads (by inserting a vertex at the face midpoint and each
 * of the edge midpoints).  The new vertex positions will be stored
 * in the members Vertex::newPosition, Edge::newPosition, and
 * Face::newPosition.  The values of the positions are based on
 * simple linear interpolation, e.g., the edge midpoints and face
 * centroids.
 */
void HalfedgeMesh::computeLinearSubdivisionPositions() {
  // TODO For each vertex, assign Vertex::newPosition to
  // its original position, Vertex::position.

  // TODO For each edge, assign the midpoint of the two original
  // positions to Edge::newPosition.

  // TODO For each face, assign the centroid (i.e., arithmetic mean)
  // of the original vertex positions to Face::newPosition.  Note
  // that in general, NOT all faces will be triangles!
  showError("computeLinearSubdivisionPositions() not implemented.");
}

/**
 * Compute new vertex positions for a mesh that splits each polygon
 * into quads (by inserting a vertex at the face midpoint and each
 * of the edge midpoints).  The new vertex positions will be stored
 * in the members Vertex::newPosition, Edge::newPosition, and
 * Face::newPosition.  The values of the positions are based on
 * the Catmull-Clark rules for subdivision.
 */
void HalfedgeMesh::computeCatmullClarkPositions() {
  // TODO The implementation for this routine should be
  // a lot like HalfedgeMesh::computeLinearSubdivisionPositions(),
  // except that the calculation of the positions themsevles is
  // slightly more involved, using the Catmull-Clark subdivision
  // rules. (These rules are outlined in the Developer Manual.)

  // TODO face

  // TODO edges

  // TODO vertices
  showError("computeCatmullClarkPositions() not implemented.");
}

/**
 * Assign a unique integer index to each vertex, edge, and face in
 * the mesh, starting at 0 and incrementing by 1 for each element.
 * These indices will be used as the vertex indices for a mesh
 * subdivided using Catmull-Clark (or linear) subdivision.
 */
void HalfedgeMesh::assignSubdivisionIndices() {
  // TODO Start a counter at zero; if you like, you can use the
  // "Index" type (defined in halfedgeMesh.h)

  // TODO Iterate over vertices, assigning values to Vertex::index

  // TODO Iterate over edges, assigning values to Edge::index

  // TODO Iterate over faces, assigning values to Face::index
  showError("assignSubdivisionIndices() not implemented.");
}

/**
 * Build a flat list containing all the vertex positions for a
 * Catmull-Clark (or linear) subdivison of this mesh.  The order of
 * vertex positions in this list must be identical to the order
 * of indices assigned to Vertex::newPosition, Edge::newPosition,
 * and Face::newPosition.
 */
void HalfedgeMesh::buildSubdivisionVertexList(vector<Vector3D>& subDVertices) {
  // TODO Resize the vertex list so that it can hold all the vertices.

  // TODO Iterate over vertices, assigning Vertex::newPosition to the
  // appropriate location in the new vertex list.

  // TODO Iterate over edges, assigning Edge::newPosition to the appropriate
  // location in the new vertex list.

  // TODO Iterate over faces, assigning Face::newPosition to the appropriate
  // location in the new vertex list.
  showError("buildSubdivisionVertexList() not implemented.");
}

/**
 * Build a flat list containing all the quads in a Catmull-Clark
 * (or linear) subdivision of this mesh.  Each quad is specified
 * by a vector of four indices (i,j,k,l), which come from the
 * members Vertex::index, Edge::index, and Face::index.  Note that
 * the ordering of these indices is important because it determines
 * the orientation of the new quads; it is also important to avoid
 * "bowties."  For instance, (l,k,j,i) has the opposite orientation
 * of (i,j,k,l), and if (i,j,k,l) is a proper quad, then (i,k,j,l)
 * will look like a bowtie.
 */
void HalfedgeMesh::buildSubdivisionFaceList(vector<vector<Index> >& subDFaces) {
  // TODO This routine is perhaps the most tricky step in the construction of
  // a subdivision mesh (second, perhaps, to computing the actual Catmull-Clark
  // vertex positions).  Basically what you want to do is iterate over faces,
  // then for each for each face, append N quads to the list (where N is the
  // degree of the face).  For this routine, it may be more convenient to simply
  // append quads to the end of the list (rather than allocating it ahead of
  // time), though YMMV.  You can of course iterate around a face by starting
  // with its first halfedge and following the "next" pointer until you get
  // back to the beginning.  The tricky part is making sure you grab the right
  // indices in the right order---remember that there are indices on vertices,
  // edges, AND faces of the original mesh.  All of these should get used.  Also
  // remember that you must have FOUR indices per face, since you are making a
  // QUAD mesh!

  // TODO iterate over faces
  // TODO loop around face
  // TODO build lists of four indices for each sub-quad
  // TODO append each list of four indices to face list
  showError("buildSubdivisionFaceList() not implemented.");
}

FaceIter HalfedgeMesh::bevelVertex(VertexIter v) {
  // TODO This method should replace the vertex v with a face, corresponding to
  // a bevel operation. It should return the new face.  NOTE: This method is
  // responsible for updating the *connectivity* of the mesh only---it does not
  // need to update the vertex positions.  These positions will be updated in
  // HalfedgeMesh::bevelVertexComputeNewPositions (which you also have to
  // implement!)

  showError("bevelVertex() not implemented.");
  return facesBegin();
}

FaceIter HalfedgeMesh::bevelEdge(EdgeIter e) {
  // TODO This method should replace the edge e with a face, corresponding to a
  // bevel operation. It should return the new face.  NOTE: This method is
  // responsible for updating the *connectivity* of the mesh only---it does not
  // need to update the vertex positions.  These positions will be updated in
  // HalfedgeMesh::bevelEdgeComputeNewPositions (which you also have to
  // implement!)

  showError("bevelEdge() not implemented.");
  return facesBegin();
}

FaceIter HalfedgeMesh::bevelFace(FaceIter f) {
  // TODO This method should replace the face f with an additional, inset face
  // (and ring of faces around it), corresponding to a bevel operation. It
  // should return the new face.  NOTE: This method is responsible for updating
  // the *connectivity* of the mesh only---it does not need to update the vertex
  // positions.  These positions will be updated in
  // HalfedgeMesh::bevelFaceComputeNewPositions (which you also have to
  // implement!)

  showError("bevelFace() not implemented.");
  return facesBegin();
}


void HalfedgeMesh::bevelFaceComputeNewPositions(
    vector<Vector3D>& originalVertexPositions,
    vector<HalfedgeIter>& newHalfedges, double normalShift,
    double tangentialInset) {
  // TODO Compute new vertex positions for the vertices of the beveled face.
  //
  // These vertices can be accessed via newHalfedges[i]->vertex()->position for
  // i = 1, ..., newHalfedges.size()-1.
  //
  // The basic strategy here is to loop over the list of outgoing halfedges,
  // and use the preceding and next vertex position from the original mesh
  // (in the originalVertexPositions array) to compute an offset vertex
  // position.
  //
  // Note that there is a 1-to-1 correspondence between halfedges in
  // newHalfedges and vertex positions
  // in orig.  So, you can write loops of the form
  //
  // for( int i = 0; i < newHalfedges.size(); hs++ )
  // {
  //    Vector3D pi = originalVertexPositions[i]; // get the original vertex
  //    position correponding to vertex i
  // }
  //

}

void HalfedgeMesh::bevelVertexComputeNewPositions(
    Vector3D originalVertexPosition, vector<HalfedgeIter>& newHalfedges,
    double tangentialInset) {
  // TODO Compute new vertex positions for the vertices of the beveled vertex.
  //
  // These vertices can be accessed via newHalfedges[i]->vertex()->position for
  // i = 1, ..., hs.size()-1.
  //
  // The basic strategy here is to loop over the list of outgoing halfedges,
  // and use the preceding and next vertex position from the original mesh
  // (in the orig array) to compute an offset vertex position.

}

void HalfedgeMesh::bevelEdgeComputeNewPositions(
    vector<Vector3D>& originalVertexPositions,
    vector<HalfedgeIter>& newHalfedges, double tangentialInset) {
  // TODO Compute new vertex positions for the vertices of the beveled edge.
  //
  // These vertices can be accessed via newHalfedges[i]->vertex()->position for
  // i = 1, ..., newHalfedges.size()-1.
  //
  // The basic strategy here is to loop over the list of outgoing halfedges,
  // and use the preceding and next vertex position from the original mesh
  // (in the orig array) to compute an offset vertex position.
  //
  // Note that there is a 1-to-1 correspondence between halfedges in
  // newHalfedges and vertex positions
  // in orig.  So, you can write loops of the form
  //
  // for( int i = 0; i < newHalfedges.size(); i++ )
  // {
  //    Vector3D pi = originalVertexPositions[i]; // get the original vertex
  //    position correponding to vertex i
  // }
  //

}

void HalfedgeMesh::splitPolygons(vector<FaceIter>& fcs) {
  for (auto f : fcs) splitPolygon(f);
}

void HalfedgeMesh::splitPolygon(FaceIter f) {
  // TODO: (meshedit) 
  // Triangulate a polygonal face
  showError("splitPolygon() not implemented.");
}

EdgeRecord::EdgeRecord(EdgeIter& _edge) : edge(_edge) {
  // TODO: (meshEdit)
  // Compute the combined quadric from the edge endpoints.
  // -> Build the 3x3 linear system whose solution minimizes the quadric error
  //    associated with these two endpoints.
  // -> Use this system to solve for the optimal position, and store it in
  //    EdgeRecord::optimalPoint.
  // -> Also store the cost associated with collapsing this edg in
  //    EdgeRecord::Cost.
}

void MeshResampler::upsample(HalfedgeMesh& mesh)
// This routine should increase the number of triangles in the mesh using Loop
// subdivision.
{
  // TODO: (meshEdit)
  // Compute new positions for all the vertices in the input mesh, using
  // the Loop subdivision rule, and store them in Vertex::newPosition.
  // -> At this point, we also want to mark each vertex as being a vertex of the
  //    original mesh.

	//map<HalfedgeIter, double> seen;
	double u;
	
	for (auto v = mesh.verticesBegin(); v != mesh.verticesEnd(); v++)
	{
		//v->getNeighborhood(seen, 1);
		vector<VertexIter> adjver; 
		double degree = v->degree();
		if (degree==3)
		{
			u = 3.f / 8.f;
		}
		else
			u = 3.f / (degree * 8.f);
		v->newPosition = ((1.0-(degree*u)) * v->position);
		v->newPosition += u * (v->neighborhoodCentroid() * degree);
		//for (map<HalfedgeIter, double>::iterator it = seen.begin(); it != seen.end(); ++it) 
		//{
		//	v->newPosition += u*(it->first->vertex()->position);
		//}
		v->isNew = false;
	}
	
	// -> Next, compute the updated vertex positions associated with edges, and
	//    store it in Edge::newPosition.
	for (EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++)
	{
		Vector3D a = e->halfedge()->vertex()->position;
		Vector3D b = e->halfedge()->twin()->vertex()->position;
		Vector3D c = e->halfedge()->next()->next()->vertex()->position;
		Vector3D d = e->halfedge()->twin()->next()->next()->vertex()->position;
		e->newPosition = ((3 * (a + b)) / 8) + ((c + d) / 8);
		e->isNew = false;
	}


	int num_edges= mesh.nEdges();
	EdgeIter e = mesh.edgesBegin();
	for(int i=0;i<num_edges;i++)
	{
		// get the next edge NOW!
		EdgeIter nextEdge = e;
		nextEdge++;

		// now, even if splitting the edge deletes it...
		if (e->isNew == false)
		{

			VertexIter NewVertex = mesh.splitEdge(e);
			NewVertex->isNew = true;
			NewVertex->newPosition = e->newPosition;

			HalfedgeIter HalfEdge= NewVertex->halfedge();
			
			HalfedgeIter previous = HalfEdge->next()->next();
			previous ->edge()->isNew = true;
			HalfEdge->twin()->next()->edge()->isNew = true;
			
		}
		// ...we still have a valid reference to the next edge.
		e = nextEdge;
	}


	for (EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++)
	{
		if (e->isNew == true && (e->halfedge()->vertex()->isNew != e->halfedge()->twin()->vertex()->isNew))
		{
			mesh.flipEdge(e);			
		}

	}

	for (VertexIter v = mesh.verticesBegin(); v != mesh.verticesEnd(); v++)
	{
		v->position = v->newPosition;
	}

  
  // -> Next, we're going to split every edge in the mesh, in any order.  For
  //    future reference, we're also going to store some information about which
  //    subdivided edges come from splitting an edge in the original mesh, and
  //    which edges are new, by setting the flat Edge::isNew. Note that in this
  //    loop, we only want to iterate over edges of the original mesh.
  //    Otherwise, we'll end up splitting edges that we just split (and the
  //    loop will never end!)
  // -> Now flip any new edge that connects an old and new vertex.
  // -> Finally, copy the new vertex positions into final Vertex::position.

  // Each vertex and edge of the original surface can be associated with a
  // vertex in the new (subdivided) surface.
  // Therefore, our strategy for computing the subdivided vertex locations is to
  // *first* compute the new positions
  // using the connectity of the original (coarse) mesh; navigating this mesh
  // will be much easier than navigating
  // the new subdivided (fine) mesh, which has more elements to traverse.  We
  // will then assign vertex positions in
  // the new mesh based on the values we computed for the original mesh.

  // Compute updated positions for all the vertices in the original mesh, using
  // the Loop subdivision rule.

  // Next, compute the updated vertex positions associated with edges.

  // Next, we're going to split every edge in the mesh, in any order.  For
  // future
  // reference, we're also going to store some information about which
  // subdivided
  // edges come from splitting an edge in the original mesh, and which edges are
  // new.
  // In this loop, we only want to iterate over edges of the original
  // mesh---otherwise,
  // we'll end up splitting edges that we just split (and the loop will never
  // end!)

  // Finally, flip any new edge that connects an old and new vertex.

  // Copy the updated vertex positions to the subdivided mesh.
	
	//showError("upsample() not implemented.");
}

void MeshResampler::downsample(HalfedgeMesh& mesh) {
  // TODO: (meshEdit)
  // Compute initial quadrics for each face by simply writing the plane equation
  // for the face in homogeneous coordinates. These quadrics should be stored
  // in Face::quadric
  // -> Compute an initial quadric for each vertex as the sum of the quadrics
  //    associated with the incident faces, storing it in Vertex::quadric
  // -> Build a priority queue of edges according to their quadric error cost,
  //    i.e., by building an EdgeRecord for each edge and sticking it in the
  //    queue.
  // -> Until we reach the target edge budget, collapse the best edge. Remember
  //    to remove from the queue any edge that touches the collapsing edge
  //    BEFORE it gets collapsed, and add back into the queue any edge touching
  //    the collapsed vertex AFTER it's been collapsed. Also remember to assign
  //    a quadric to the collapsed vertex, and to pop the collapsed edge off the
  //    top of the queue.
  showError("downsample() not implemented.");
}

void MeshResampler::resample(HalfedgeMesh& mesh) {
  // TODO: (meshEdit)
  // Compute the mean edge length.
  // Repeat the four main steps for 5 or 6 iterations
  // -> Split edges much longer than the target length (being careful about
  //    how the loop is written!)
  // -> Collapse edges much shorter than the target length.  Here we need to
  //    be EXTRA careful about advancing the loop, because many edges may have
  //    been destroyed by a collapse (which ones?)
  // -> Now flip each edge if it improves vertex degree
  // -> Finally, apply some tangential smoothing to the vertex positions
  showError("resample() not implemented.");
}

}  // namespace CMU462
