# Design-Patterns-Project
This a design-pattern project for COS 214 of the University of Pretoria by the group TSP.
We will model a Formula one team, specifically the logistics and racing, using at least 10 design patterns. 

The project will be coded in C++ 20 and submitted on the 9th of Novemeber 2020.

    The following patterns were used:

          1. Composite
          2. Prototype
          3. Factory
          4. Builder
          5. Memento
          6. Iterator
          7. State
          8. Observer
          9. Mediator
         10. Strategy


Classes in Patterns:

        Composite:  Circuit, RaceTrack, CompositeRoad
                    Result, RaceSeasonResult, GrandPrixResult, 
                    RaceResult, LapResult, SimulationResult,
                    Car, CarComposite, Engine, Body, Chassis, 
                    Suspension, SteeringWheel, CoolingSystem, 
                    Electronics, Tyre
                    
        Prototype:  Car
                    CarComposite, Art,  
                    Engine, Body, Chassis, 
                    Suspension, SteeringWheel, 
                    CoolingSystem, Electronics, Tyre
                    Container, GarageEquipment, CateringEquipment,
                    carComponent, Logistics, LogisticStrategy 


        Factory:    CarPartFactory
                    EngineFactory, ChassisFactory, 
                    TransmissionFactory, SteeringFactory, 
                    CoolingFactory, BodyFactory, SuspensionFactory, 
                    BrakesFactory, ElectronicsFactory, CarPart
                    Engine, Body, Chassis, Suspension, 
                    SteeringWheel, CoolingSystem, Electronics
        
        Builder:    CarBuilder, CarComposite, CarFactory
                    EngineFactory, ChassisFactory, TransmissionFactory, 
                    SteeringFactory, CoolingFactory, BodyFactory, 
                    SuspensionFactory, BrakesFactory, ElectronicsFactory
        
        Memento:    TransportVehicle, CarMemento, CarComposite 
        
        Iterator:   Iterator, CircuitIterator
                    Circuit, RaceTrack       
        
        State:      GrandPrix, Race, RaceState
                    PracticeState, QualifyingState,OfficialState
                    Driver, DriverStrategy, AggressiveDriving, 
                    DefensiveDriving and ControlledDriving,
                    EngineeringDepartment, Simulation,WindTunnel, 
                    HandlingSimulation, AccelerationSimulation, SpeedSimulation
        
        Observer:   Subject, SeasonSubject, RaceTeam
                    QualifyingRaceSubject, OfficialRaceSubject,
                    EngineeringDepartment, EngineDepartment,
                    ChassisDepartment, ElectronicsDepartment, 
                    AeroDynamicsDepartment, TransmissionDepartment, 
                    BrakesDepartment, CoolingDepartment, SuspensionDepartment
        
        Mediator:   Pitstop, CarStop, Pitcrew, 
                    Tyre, PartReplacer
        
        Strategy:   TyreStrategy, Hard, Medium,
                    Soft, TyreStrategy


To compile the code:
        
        See readme.txt

To create instances of classes:
    
 //need to talk about this

    The group members are as follows:

            Brenton        Stroberg         u17015741
            Michael        Stroh            u17023557
            Timothy        Hill             u17112592
            Kayla          Latty            u17360812
            Alex           Human            u19069716

                                            -ordered by emplid
