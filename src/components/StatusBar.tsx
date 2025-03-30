import { useState, useEffect } from "react";
import { Progress } from "@/components/ui/progress";

interface StatusBarProps {
  mode: string;
  itemCount?: number;
  isLoading?: boolean;
  loadProgress?: number;
}

const StatusBar = ({ mode, itemCount = 0, isLoading = false, loadProgress = 0 }: StatusBarProps) => {
  const [time, setTime] = useState<string>("");
  
  useEffect(() => {
    const updateTime = () => {
      const now = new Date();
      const timeString = now.toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' });
      setTime(timeString);
    };
    
    updateTime();
    const interval = setInterval(updateTime, 60000);
    
    return () => clearInterval(interval);
  }, []);
  
  const isEditMode = mode === "Edit";
  
  return (
    <div className={`flex flex-col ${isEditMode ? 'bg-[#da4b4b]' : 'bg-cyrus-blue'} text-white text-xs`}>
      <div className="flex items-center justify-between px-4 py-1">
        <div>Mode: {mode}</div>
        <div>Items: {itemCount}</div>
        {isLoading && (
          <div className="flex items-center">
            <div className="animate-pulse mr-2">⚡</div>
            <div>Lade Daten: {loadProgress}%</div>
          </div>
        )}
        <div>{time}</div>
      </div>
      
      {isLoading && (
        <Progress 
          value={loadProgress} 
          className="h-1 bg-cyrus-dark-lighter" 
        />
      )}
    </div>
  );
};

export default StatusBar;
