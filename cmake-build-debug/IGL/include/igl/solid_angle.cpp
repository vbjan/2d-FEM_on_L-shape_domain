#include "solid_angle.h"
#include "PI.h"
#include <cmath>

template <
  typename DerivedA,
  typename DerivedB,
  typename DerivedC,
  typename DerivedP>
IGL_INLINE typename DerivedA::Scalar igl::solid_angle(
  const Eigen::MatrixBase<DerivedA> & A,
  const Eigen::MatrixBase<DerivedB> & B,
  const Eigen::MatrixBase<DerivedC> & C,
  const Eigen::MatrixBase<DerivedP> & P)
{
  typedef typename DerivedA::Scalar SType;
  // Gather vectors to corners
  Eigen::Matrix<SType,3,3> v;
  // Don't use this since it will freak out for templates with != 3 size
  //v<< (A-P),(B-P),(C-P);
  for(int d = 0;d<3;d++)
  {
    v(0,d) = A(d)-P(d);
    v(1,d) = B(d)-P(d);
    v(2,d) = C(d)-P(d);
  }
  Eigen::Matrix<SType,1,3> vl = v.rowwise().norm();
  //printf("\n");
  // Compute determinant
  SType detf = 
    v(0,0)*v(1,1)*v(2,2)+
    v(1,0)*v(2,1)*v(0,2)+
    v(2,0)*v(0,1)*v(1,2)-
    v(2,0)*v(1,1)*v(0,2)-
    v(1,0)*v(0,1)*v(2,2)-
    v(0,0)*v(2,1)*v(1,2);
  // Compute pairwise dotproducts
  Eigen::Matrix<SType,1,3> dp;
  dp(0) = v(1,0)*v(2,0);
  dp(0) += v(1,1)*v(2,1);
  dp(0) += v(1,2)*v(2,2);
  dp(1) = v(2,0)*v(0,0);
  dp(1) += v(2,1)*v(0,1);
  dp(1) += v(2,2)*v(0,2);
  dp(2) = v(0,0)*v(1,0);
  dp(2) += v(0,1)*v(1,1);
  dp(2) += v(0,2)*v(1,2);
  // Compute winding number
  // Only divide by TWO_PI instead of 4*pi because there was a 2 out front
  return atan2(detf,
    vl(0)*vl(1)*vl(2) + 
    dp(0)*vl(0) +
    dp(1)*vl(1) +
    dp(2)*vl(2)) / (2.*igl::PI);
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<double, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<float, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 2, 1, 1, 2> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Matrix<float, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 2, 1, 1, 2> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<double, 3, 1, 0, 3, 1> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 3, 1, 0, 3, 1> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::solid_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<double, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&);
#endif
