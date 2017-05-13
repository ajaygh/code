//It decouples business tier with presentation tier.
//It reduces communication or remote function lookup in business tier
//from presentation tier.
interface BusinessService {
    public void doProcessing() ;
}

class EJBService implements BusinessService {
    @Override
    public void doProcessing(){
        System.out.println("Processing client task by invoking ejb service.");      
    }    
}

class JMSService implements BusinessService {
    @Override
    public void doProcessing(){
        System.out.println("Processing client task by invoking jms service.");      
    }    
}

class BusinessLookUp{
    public BusinessService getBusinessService(String serviceType){
        switch(serviceType){
            case "ejb":
                return new EJBService();
            case "jms":
                return new JMSService();       
        }
        return null;
    }
}

class BusinessDelegate {
    private BusinessLookUp businessLookUp = new BusinessLookUp();
    private BusinessService businessService;
    private String serviceType;

    public void setServiceType(String serviceType){
        this.serviceType = serviceType;
    }

    public void doTask(){
        businessService = businessLookUp.getBusinessService(serviceType);
        businessService.doProcessing();
    }
}

class Client {
    private BusinessDelegate businessDelegate;
    public Client(BusinessDelegate businessDelegate){
        this.businessDelegate = businessDelegate;
    }
    public void doTask(){
        businessDelegate.doTask();
    }
}

public class BusinessDelegateDemo {
    public static void main(String args[]){
        BusinessDelegate businessDelegate = new BusinessDelegate();
        businessDelegate.setServiceType("ejb");

        Client client = new Client(businessDelegate);
        client.doTask();

        businessDelegate.setServiceType("jms");
        client.doTask();        
    }
}