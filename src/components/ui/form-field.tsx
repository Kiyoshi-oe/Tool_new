import React from "react";
import { cn } from "@/lib/utils";
import { Input } from "./input";
import { Check, AlertCircle, Info, ChevronDown } from "lucide-react";
import SelectCustom from "./select-custom";

interface FormFieldProps {
  id: string;
  label: string;
  type?: "text" | "number" | "password" | "email" | "select" | "textarea";
  value: string | number;
  onChange: (value: string) => void;
  placeholder?: string;
  disabled?: boolean;
  readOnly?: boolean;
  className?: string;
  inputClassName?: string;
  error?: string;
  isValid?: boolean;
  min?: number;
  max?: number;
  step?: number;
  helperText?: string;
  options?: string[] | { value: string; label: string }[];
}

export const FormField: React.FC<FormFieldProps> = ({
  id,
  label,
  type = "text",
  value,
  onChange,
  placeholder = "",
  disabled = false,
  readOnly = false,
  className = "",
  inputClassName = "",
  error,
  isValid = false,
  min,
  max,
  step,
  helperText,
  options = [],
}) => {
  const hasError = !!error;
  const showValidIcon = isValid && !hasError;

  const renderInput = () => {
    if (type === "select" && options.length > 0) {
      return (
        <SelectCustom
          id={id}
          value={value as string}
          onChange={onChange}
          disabled={disabled}
          options={options}
          className={cn(
            inputClassName,
            hasError && "border-destructive focus-visible:ring-destructive",
            readOnly && "opacity-75 cursor-not-allowed",
            disabled && "bg-cyrus-dark-lighter"
          )}
        />
      );
    } else if (type === "number") {
      return (
        <Input
          id={id}
          type="number"
          value={value}
          onChange={(e) => onChange(e.target.value)}
          placeholder={placeholder}
          disabled={disabled}
          readOnly={readOnly}
          className={cn(
            inputClassName,
            "dark-mode-number-input",
            hasError && "border-destructive focus-visible:ring-destructive",
            showValidIcon && "pr-10",
            readOnly && "opacity-75 cursor-not-allowed",
            disabled && "bg-cyrus-dark-lighter"
          )}
          min={min}
          max={max}
          step={step}
          aria-invalid={hasError}
        />
      );
    } else {
      return (
        <Input
          id={id}
          type={type}
          value={value}
          onChange={(e) => onChange(e.target.value)}
          placeholder={placeholder}
          disabled={disabled}
          readOnly={readOnly}
          className={cn(
            inputClassName,
            hasError && "border-destructive focus-visible:ring-destructive",
            showValidIcon && "pr-10",
            readOnly && "opacity-75 cursor-not-allowed",
            disabled && "bg-cyrus-dark-lighter"
          )}
          min={min}
          max={max}
          step={step}
          aria-invalid={hasError}
        />
      );
    }
  };

  return (
    <div className={cn("space-y-1", className)}>
      {label && (
        <label
          htmlFor={id}
          className="text-sm font-medium leading-none peer-disabled:cursor-not-allowed peer-disabled:opacity-70"
        >
          {label}
        </label>
      )}
      
      <div className="relative">
        {renderInput()}
        
        {showValidIcon && type !== 'select' && (
          <Check className="h-4 w-4 absolute right-3 top-1/2 transform -translate-y-1/2 text-green-500" />
        )}
        
        {hasError && type !== 'select' && (
          <AlertCircle className="h-4 w-4 absolute right-3 top-1/2 transform -translate-y-1/2 text-destructive" />
        )}
      </div>
      
      {hasError && (
        <p className="text-sm text-destructive font-medium">{error}</p>
      )}

      {helperText && (
        <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
          <Info size={14} />
          <span>{helperText}</span>
        </p>
      )}
    </div>
  );
};
