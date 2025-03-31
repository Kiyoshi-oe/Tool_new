import React, { CSSProperties } from "react";
import { ChevronDown } from "lucide-react";
import { cn } from "@/lib/utils";

interface SelectCustomProps {
  className?: string;
  options: { value: string; label: string }[] | string[];
  value: string;
  onChange: (value: string) => void;
  disabled?: boolean;
  name?: string;
  id?: string;
}

export const SelectCustom: React.FC<SelectCustomProps> = ({
  className,
  options,
  value,
  onChange,
  disabled = false,
  ...props
}) => {
  const handleChange = (e: React.ChangeEvent<HTMLSelectElement>) => {
    onChange(e.target.value);
  };

  // Stile für alle Browser, um den nativen Pfeil zu entfernen
  const noArrowStyles: CSSProperties = {
    WebkitAppearance: "none",
    MozAppearance: "none",
    appearance: "none" as "none",
    backgroundImage: "none"
  };

  return (
    <div className="relative select-wrapper">
      <select
        value={value}
        onChange={handleChange}
        disabled={disabled}
        className={cn(
          "flex h-10 w-full rounded-md border border-input bg-cyrus-dark-lighter px-3 py-2 text-base text-white appearance-none pr-10 ring-offset-background focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 disabled:cursor-not-allowed disabled:opacity-50 disabled:bg-cyrus-dark-lighter md:text-sm transition-all duration-200 select-no-arrow",
          className
        )}
        style={noArrowStyles}
        {...props}
      >
        {options.map((option) => {
          if (typeof option === 'string') {
            return (
              <option key={option} value={option}>
                {option}
              </option>
            );
          } else {
            return (
              <option key={option.value} value={option.value}>
                {option.label}
              </option>
            );
          }
        })}
      </select>
      <div className="absolute inset-y-0 right-0 flex items-center pr-3 pointer-events-none text-gray-400 z-10">
        <ChevronDown className="h-4 w-4" />
      </div>
    </div>
  );
};

export default SelectCustom; 