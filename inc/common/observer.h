#pragma once

#include <vector>

namespace svg {

/**
 * \interface IObserver
 * @brief For notifications
 */
class IObserver
{
public:
   /**
    * @brief Update derived classes
    */
   virtual void Update() = 0;
};

/**
 * \interface IObservable
 * @brief For monitoring
 */
class IObservable
{
public:
   /**
    * @brief Adding a new observer for notify
    * 
    * @param m_pObserver Point to CObserver
    */
   void AddObserver(IObserver* m_pObserver)
   {
      m_vObservers.push_back(m_pObserver);
   }

   /**
    * @brief Notify all observers
    */
   void NotifyUpdate()
   {
      for ( auto& observer : m_vObservers) {
         observer->Update();
      }
   }
private:
   std::vector<IObserver*> m_vObservers;
};

} /* end svg::*/