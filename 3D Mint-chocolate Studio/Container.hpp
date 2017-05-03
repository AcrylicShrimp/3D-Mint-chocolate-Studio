
/*
	2017.04.28
	Created by AcrylicShrimp.
*/

namespace D3MCS::Utility
{
	template<class LoadType> Container<LoadType>::Container() :
		bLoaded{false}
	{
		//Empty.
	}

	template<class LoadType> template<class ...ContructorParameter> Container<LoadType>::Container(ContructorParameter &&...sConstructorParam) :
		bLoaded{true}
	{
		new (this->vLoad) LoadType(std::forward<LoadType>(sConstructorParam)...);
	}

	template<class LoadType> Container<LoadType>::Container(const Container<LoadType> &sSrc) :
		bLoaded{sSrc.bLoaded}
	{
		if (this->bLoaded)
			new (this->vLoad) LoadType(*reinterpret_cast<LoadType *>(sSrc.vLoad));
	}

	template<class LoadType> Container<LoadType>::Container(Container<LoadType> &&sSrc) :
		bLoaded{sSrc.bLoaded}
	{
		if (this->bLoaded)
			new (this->vLoad) LoadType(std::move(*reinterpret_cast<LoadType *>(sSrc.vLoad)));
	}

	template<class LoadType> Container<LoadType>::~Container()
	{
		this->fin();
	}

	template<class LoadType> Container<LoadType> &Container<LoadType>::operator=(const Container<LoadType> &sSrc)
	{
		if (&sSrc == this)
			return *this;

		if (this->bLoaded && sSrc.bLoaded)
			*reinterpret_cast<LoadType *>(this->vLoad) = *reinterpret_cast<LoadType *>(sSrc.vLoad);

		return *this;
	}

	template<class LoadType> Container<LoadType> &Container<LoadType>::operator=(Container<LoadType> &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		if (this->bLoaded && sSrc.bLoaded)
			*reinterpret_cast<LoadType *>(this->vLoad) = std::move(*reinterpret_cast<LoadType *>(sSrc.vLoad));

		return *this;
	}
}