/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2015 Johannes Goettker-Schnetmann
 Copyright (C) 2015 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file bsmrndcalculator.hpp
    \brief risk neutral terminal density calculator for the
    	   Black-Scholes-Merton model with constant volatility
*/

#ifndef quantlib_bsm_risk_neutral_density_calculator_hpp
#define quantlib_bsm_risk_neutral_density_calculator_hpp

#include <ql/experimental/finitedifferences/riskneutraldensitycalculator.hpp>

namespace QuantLib {
	class YieldTermStructure;

	class BSMRNDCalculator : public RiskNeutralDensityCalculator {
	public:
		BSMRNDCalculator(
			const Real x0, // x0 = ln(S_0)
			const Volatility vol,
			const boost::shared_ptr<YieldTermStructure>& rTS,
			const boost::shared_ptr<YieldTermStructure>& qTS);

		// x = ln(S)
		Real pdf(Real x, Time t) const;
		Real cdf(Real x, Time t) const;
		Real invcdf(Real q, Time t) const;

	private:
		std::pair<Real, Volatility> distributionParams(Real x, Time t) const;

		const Real x0_;
		const Volatility vol_;
		const boost::shared_ptr<YieldTermStructure> rTS_;
		const boost::shared_ptr<YieldTermStructure> qTS_;
	};
}

#endif
