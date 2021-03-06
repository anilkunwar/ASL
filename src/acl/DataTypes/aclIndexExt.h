/*
 * Advanced Simulation Library <http://asl.org.il>
 * 
 * Copyright 2015 Avtech Scientific <http://avtechscientific.com>
 *
 *
 * This file is part of Advanced Simulation Library (ASL).
 *
 * ASL is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, version 3 of the License.
 *
 * ASL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with ASL. If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef ACLINDEXEXT_H
#define ACLINDEXEXT_H

#include "../aclElementBase.h"

namespace acl
{
	/**
	 The class creates OpenCl code which corresponds to "index" for the case 
	 with simple kernel. This means that in the case of kernel with vector length v
	 and unaligned = false it generates code
	 \code
	 	{v*index, v*index+1, ... , v*index+v-1}
	 \endcode
	 with vector length v and unaligned = true it generates code
	 \code
	 	{index, index+1, ... , index+v-1}
	 \endcode
	 */
	class IndexExt: public ElementBase
	{
		public:
			IndexExt(unsigned int s = 0);
			virtual string str(const KernelConfiguration & kernelConfig) const;
			virtual string getName() const;
			virtual string getTypeSignature(const KernelConfiguration & kernelConfig) const;
			virtual string getLocalDeclaration(const KernelConfiguration & kernelConfig) const;
			virtual void addToKernelSource(vector<Element> & arguments,
			                               vector<Element> & localDeclarations) const;
			virtual void setAsArgument(cl::Kernel & kernel, unsigned int argumentIndex) const;
	};
} // namespace acl

#endif // ACLINDEXEXT_H
