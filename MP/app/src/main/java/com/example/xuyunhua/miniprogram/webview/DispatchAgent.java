package com.example.xuyunhua.miniprogram.webview;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class DispatchAgent {
    private HashMap<String,iInvoke>event_core;
    private DispatchAgent(){
        event_core = new HashMap<>();
    };

    public int currentEventCount(){
        if(event_core == null)return 0;
        return event_core.size();
    }

    public boolean registerEvent(String name,iInvoke func){
        if(name == null || name.length()<1) return false;
        if(event_core == null) return false;
        event_core.put(name,func);
        return true;
    }

    public boolean unRegisterEvent(String name){
        if(name == null || name.length()<1) return false;
        if(event_core == null)return false;
        if(event_core.containsKey(name)){
            event_core.remove(name);
            return true;
        }
        return false;
    }

    public iInvoke obtainEventFunc(String name){
        if(name == null || name.length()<0)return null;
        if(event_core.containsKey(name)){
            return event_core.get(name);
        }
        return null;
    }
    public void clear(){
        if(event_core ==null)return;
        Set<String> keySet = event_core.keySet();
        Iterator<String> iterator = keySet.iterator();
        while (iterator.hasNext()){
            String key = iterator.next();
            event_core.remove(key);
        }
        event_core = null;
    }

    public static DispatchAgent getInstance(){
        return agentIntanceHolder.agent;
    }

    public static class agentIntanceHolder{
        public static final DispatchAgent agent = new DispatchAgent();
    }
}
